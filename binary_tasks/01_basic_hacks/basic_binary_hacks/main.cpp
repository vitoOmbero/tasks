#include <cassert>
#include <iostream>

bool is_odd_binaryhack(int number) {
  bool result = false;

  result = number & 1;

  return result;
}

bool const ODD = true;
bool const EVEN = false;

void test_is_odd_binaryhack() {
  int a{5};
  int b{4};

  assert(is_odd_binaryhack(a) == ODD);
  assert(is_odd_binaryhack(b) == EVEN);
}

bool has_same_sign(int first, int second) {
  bool result{false};

  result = (first ^ second) > 0;

  return result;
}

void test_has_same_sign() {
  int a{-42};
  int b{42};
  int c = 0;
  assert(has_same_sign(a, b) == false);
  assert(has_same_sign(c, b) == true);
}

const int THREE{3};
const int ONE{1};
const int TWO{2};
const int FIVE{5};
const int FOUR{4};
const int ZERO{0};

void test_binary_increment() {
  // -x = ~x + 1;
  // => -~x = ~~x + 1 <=> -~x = x + 1;

  assert(FOUR + ONE == -~FOUR);
  assert(FIVE == -~FOUR);

  assert(TWO + ONE == -~TWO);
  assert(THREE == -~TWO);

  assert(ZERO + ONE == -~ZERO);
  assert(ONE == -~ZERO);
}

void test_binary_swap() {
  int a = FIVE;
  int b = ONE;

  if (a != b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
  }

  assert(a == ONE);
  assert(b == FIVE);
}

int invert_bit(int number, char bit_1_based_index) {
  int result{0};
  int mask{1 << (bit_1_based_index - 1)};
  result = number ^ mask;
  return result;

  /*
   * result = number & ~mask; // turn off bit
   * result = number | mask;  // turn on bit
   * result = number & mask;  // check if the bit is set to 1
   */
}

int turn_off_bit(int number, char bit_1_based_index) {
  return number & ~(1 << (bit_1_based_index - 1));
}
int turn_on_bit(int number, char bit_1_based_index) {
  return number | (1 << (bit_1_based_index - 1));
}
int check_bit(int number, char bit_1_based_index) {
  return number & (1 << (bit_1_based_index - 1));
}

void test_invert_check_turn_on_off_bit() {
  int a{0b0101010};  // 42
  int b{0b0100010};  // 34

  int inv_a = invert_bit(a, FOUR);
  int inv_b = invert_bit(b, FOUR);

  assert(inv_a == b);
  assert(a == inv_b);

  assert(turn_off_bit(a, FOUR) == b);
  assert(turn_on_bit(b, FOUR) == a);
  assert(check_bit(a, FOUR) > 0);
  assert(check_bit(b, FOUR) == 0);
};

int main() {
  using namespace std;

  test_is_odd_binaryhack();
  test_has_same_sign();  // TODO: use bitset for showing bit representation of
                         // int
  test_binary_increment();
  test_binary_swap();
  test_invert_check_turn_on_off_bit();

  cout << endl;
  cout << "==> All asserts were passed! <==" << endl;
  cout << endl;
  return 0;
}
