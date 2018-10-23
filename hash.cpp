#include "fmt/format.h"
#include "openssl/sha.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

string sha256(const string text) {
  int sha_success;
  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_CTX sha256;

  sha_success = SHA256_Init(&sha256);

  if (sha_success == 0) {
    cerr << "couldn't initialize sha256" << endl;
    exit(EXIT_FAILURE);
  }

  sha_success = SHA256_Update(&sha256, text.c_str(), text.size());

  if (sha_success == 0) {
    cerr << "couldn't update sha256" << endl;
    exit(EXIT_FAILURE);
  }

  sha_success = SHA256_Final(hash, &sha256);

  if (sha_success == 0) {
    cerr << "couldn't finalise sha256" << endl;
    exit(EXIT_FAILURE);
  }

  stringstream stream;

  for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    stream << hex << setw(2) << setfill('0') << (int)hash[i];
  }

  return stream.str();
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    cout << "usage: " << argv[0] << " text1 [text2 [...]]" << endl;

    return EXIT_FAILURE;
  }

  for (int i = 1; i < argc; i++) {
    string text(argv[i]);
    
    fmt::print("sha256({0}) = {1}\n", text, sha256(text));
  }

  return EXIT_SUCCESS;
}
