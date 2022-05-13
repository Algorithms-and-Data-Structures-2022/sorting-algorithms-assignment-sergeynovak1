#include "assignment/merging.hpp"

#include <cassert>    // assert
#include <algorithm>  // copy

namespace assignment {

  void merge(std::vector<int>& arr, int start, int middle, int stop, std::vector<int>& buf) {
    assert(start >= 0 && start < arr.size() && stop >= start && stop < arr.size() && middle >= start && middle <= stop);

    // индексы текущих элементов левого и правого подмассивов
    int left_offset = start;
    int right_offset = middle + 1;

    // индекс текущей позиции буфера (туда будут сливаться подмассивы)
    int buf_offset = start;

    // слияния подмассивов (пока не достигли конца одного из подмассивов)
    while (left_offset <= middle && right_offset <= stop) {
      if (arr[left_offset]<= arr[right_offset]){
        buf[buf_offset] = arr[left_offset];
        left_offset ++;
      }
      else {
        buf[buf_offset] = arr[right_offset];
        right_offset ++;
      }

      // перемещаем текущую позицию вставки в буфер
      buf_offset += 1;
    }

    // сливаем остатки подмассивов (останутся элементы только одного из двух подмассивов)
    for (int i = left_offset; i <= middle; i++) {
      buf[buf_offset] = arr[i];
      buf_offset += 1;
    }


    for (int i = right_offset; i < arr.size(); i++) {
      buf[buf_offset] = arr[i];
      buf_offset += 1;
    }

    // реализуйте сливание остатков правого подмассива ...
    for (int i = 0; i<arr.size(); i++){
      arr[i] = buf[i];
    }

    // копируем результат слияния подмассивов из буфера в оригинальный массив ... std::copy или цикл for ...
  }

}  // namespace assignment