#include <iostream>

#include "Misc/Buffer/RawBuffer.h"
#include "Misc/Buffer/IndexedBuffer.h"

int main() {
  std::cout << "RawBuffer example ----------" << std::endl;
  Misc::RawBuffer buffer(32);

  int i = 45;
  char c = 'C';
  char k = 'K';

  buffer.Append(&i, sizeof(i));
  buffer.Append(&c, sizeof(c));
  buffer.Append(&k, sizeof(k));

  for (int i = 0; i < buffer.GetSize(); ++i) {
    printf("[%d] = %c\n", i, buffer.GetData()[i]);
  }

  std::cout << "IndexedBuffer example --------------------" << std::endl;

  Misc::IndexedBuffer indexedBuffer;

  indexedBuffer.Append(&i, sizeof(i));
  indexedBuffer.Append(&c, sizeof(c));
  indexedBuffer.Append(&k, sizeof(k));

  printf("Index [0] = %d\n", indexedBuffer.Get<int>(0));
  printf("Index [1] = %c\n", indexedBuffer.Get<char>(1));
  printf("Index [2] = %c\n", indexedBuffer.Get<char>(2));

  return 0;
}