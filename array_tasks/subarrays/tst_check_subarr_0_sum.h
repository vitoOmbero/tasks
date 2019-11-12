#ifndef TST_CHECK_SUBARR_0_SUM_H
#define TST_CHECK_SUBARR_0_SUM_H

#include <list>

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "consecutive_integers.h"
#include "getzerosumsubarrays_naive.h"
#include "getzerosumsubarrays_opt.h"
#include "subarray.h"
#include "zerosumsubarray.h"

using namespace testing;

TEST(check_subarr_0_sum, SubarrayTests) {
  int input[]{3, 4, -7, 3, 1, 3, 1, -4, -2, -2};

  //    The sub-arrays with 0 sum are:

  //    { 3, 4, -7 }
  //    { 4, -7, 3 }
  //    { -7, 3, 1, 3 }
  //    { 3, 1, -4 }
  //    { 3, 1, 3, 1, -4, -2, -2 }
  //    { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 }

  int n = sizeof(input) / sizeof(input[0]);
  bool output = zeroSumSubarray(input, n); // time O(n), space O(n)

  bool EXISTS = true;
  ASSERT_THAT(output, Eq(EXISTS));
}

TEST(all_subarr_0_sum_degenerate, SubarrayTests) {
  int input[]{4, 2, -3, -1, 0, 4};
  int n = sizeof(input) / sizeof(input[0]);

  std::list<Subarray> output =
      *(getZeroSumSubarrays_NAIVE(input, n)); // time O(n^2), space O(n)

  // int first[]{-3, -1, 0, 4};
  Subarray first{&input[2], &input[5]};
  // int second[]{0};
  Subarray second{&input[4], &input[4]};

  Subarray got_second = output.back();

  ASSERT_THAT(got_second.start, Eq(second.start));
  ASSERT_EQ(got_second.end, second.end);

  output.pop_back();

  Subarray got_first = output.back();

  ASSERT_THAT(got_first.start, Eq(first.start));
  ASSERT_EQ(got_first.end, first.end);

  // opt
  output = *(getZeroSumSubarrays_OPT(input, n)); // time O(n) amortized

  got_first = output.back();

  ASSERT_THAT(got_first.start, Eq(first.start));
  ASSERT_EQ(got_first.end, first.end);

  output.pop_back();
  got_first = output.back();

  ASSERT_THAT(got_second.start, Eq(second.start));
  ASSERT_EQ(got_second.end, second.end);
}

TEST(all_subarr_0_sum_average, SubarrayTests) {
  int input[]{3, 4, -7, 3, 1, 3, 1, -4, -2, -2};
  int n = sizeof(input) / sizeof(input[0]);

  std::list<Subarray> output =
      *(getZeroSumSubarrays_NAIVE(input, n)); // time O(n^2)

  //  { 3, 1, -4 }
  Subarray sub1{&input[5], &input[7]};
  //  { 3, 1, 3, 1, -4, -2, -2 }
  Subarray sub2{&input[3], &input[9]};
  //  { -7, 3, 1, 3 }
  Subarray sub3{&input[2], &input[5]};
  // { 4, -7, 3 }
  Subarray sub4{&input[1], &input[3]};
  //  { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 }
  Subarray sub5{&input[0], &input[9]};
  // { 3, 4, -7 }
  Subarray sub6{&input[0], &input[2]};

  Subarray got = output.back();

  ASSERT_THAT(got.start, Eq(sub1.start));
  ASSERT_EQ(got.end, sub1.end);

  output.pop_back();
  got = output.back();

  ASSERT_THAT(got.start, Eq(sub2.start));
  ASSERT_EQ(got.end, sub2.end);

  output.pop_back();
  got = output.back();

  ASSERT_THAT(got.start, Eq(sub3.start));
  ASSERT_EQ(got.end, sub3.end);

  output.pop_back();
  got = output.back();

  ASSERT_THAT(got.start, Eq(sub4.start));
  ASSERT_EQ(got.end, sub4.end);

  output.pop_back();
  got = output.back();

  ASSERT_EQ(got.start, sub5.start);
  ASSERT_EQ(got.end, sub5.end);

  output.pop_back();
  got = output.back();

  ASSERT_THAT(got.start, Eq(sub6.start));
  ASSERT_EQ(got.end, sub6.end);

  // opt

  output = *(getZeroSumSubarrays_OPT(input, n)); // time O(n) amortized

  got = output.back();

  ASSERT_THAT(got.start, Eq(sub5.start));
  ASSERT_EQ(got.end, sub5.end);

  output.pop_back();
  got = output.back();

  ASSERT_THAT(got.start, Eq(sub2.start));
  ASSERT_EQ(got.end, sub2.end);

  output.pop_back();
  got = output.back();

  ASSERT_THAT(got.start, Eq(sub1.start));
  ASSERT_EQ(got.end, sub1.end);

  output.pop_back();
  got = output.back();

  ASSERT_THAT(got.start, Eq(sub3.start));
  ASSERT_EQ(got.end, sub3.end);

  output.pop_back();
  got = output.back();

  ASSERT_EQ(got.start, sub4.start);
  ASSERT_EQ(got.end, sub4.end);

  output.pop_back();
  got = output.back();

  ASSERT_THAT(got.start, Eq(sub6.start));
  ASSERT_EQ(got.end, sub6.end);
}

TEST(largest_subarr_consecutive_integers, SubarrayTests) {
  //    Find largest sub-array formed by consecutive integers
  //    Given an array of integers, find largest sub-array formed by consecutive
  //    integers. The sub-array should contain all distinct values.

  int input[] = {2, 0, 2, 1, 4, 3, 1, 0};
  int n = sizeof(input) / sizeof(input[0]);

  Subarray subarr = find_max_subarr_consecutive_integers(input, n);
  Subarray expected{&input[1], &input[5]};

  ASSERT_EQ(expected, subarr);
}

#endif // TST_CHECK_SUBARR_0_SUM_H
