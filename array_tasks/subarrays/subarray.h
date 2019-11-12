#ifndef SUBARRAY_H
#define SUBARRAY_H
struct Subarray {
  const int *start;
  const int *end;

  bool operator==(const Subarray &rhs) const {
    return this->start == rhs.start && this->end == rhs.end;
  }
};
#endif // SUBARRAY_H
