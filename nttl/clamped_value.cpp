#include "clamped_value.h"
#include <iostream>


// static_casts
void nttl::static_casts_1() {
	nttl::clamped_value<int32_t,0,32767> cv1;
	nttl::clamped_value<int32_t,0,32767> cv2;
	nttl::clamped_value<int32_t,0,32767> cv3;

	auto i64_1 = static_cast<int64_t>(cv1);
	auto ui64_1 = static_cast<uint64_t>(cv1);
	auto i32_1 = static_cast<int32_t>(cv1);
	auto ui32_1 = static_cast<uint32_t>(cv1);
	auto i16_1 = static_cast<int16_t>(cv1);
	auto ui16_1 = static_cast<uint16_t>(cv1);
	
	// Illegal
	//auto i8_1 = static_cast<int8_t>(cv1);
	//auto ui8_1 = static_cast<uint8_t>(cv1);
	//auto d32_1 = static_cast<float>(cv1);
	//auto d64_1 = static_cast<double>(cv1);
}

// Ctors
void nttl::ctors_1() {
	int i0 = 0;
	int i5 = 5;
	int i32767 = 32767;
	// Illegal
	//nttl::clamped_value<int32_t,0,32767> cv1 = i0;
	//nttl::clamped_value<int32_t,0,32767> cv2 = i5;
	//nttl::clamped_value<int32_t,0,32767> cv3 = i32767;
	nttl::clamped_value<int32_t,0,32767> cv1(i0);
	nttl::clamped_value<int32_t,0,32767> cv2(i5);
	nttl::clamped_value<int32_t,0,32767> cv3(i32767);
	
	int64_t i64sc = static_cast<int64_t>(cv3);
	int64_t i64imp = cv3;

}

void nttl::plus_minus_equals_1() {
	int i0 = 0;
	int i5 = 5;
	nttl::clamped_value<int32_t,0,32767> cv1(i0);
	nttl::clamped_value<int32_t,0,32767> cv2(i5);

	auto ex1 = cv1;
	ex1 += cv2;
	ex1 += cv2;
	std::cout << ex1 << std::endl;
	ex1 -= cv2;
	ex1 -= cv2;
	std::cout << ex1 << std::endl;
	ex1 -= cv2;
	ex1 -= cv2;
	std::cout << ex1 << std::endl;
}

void nttl::compare_unlike_1() {
	int i0 = 0;
	int i5 = 5;
	nttl::clamped_value<int32_t,0,32767> cv1(i0);
	nttl::clamped_value<int32_t,0,32767> cv2(i5);

	//int64_t i64_a = 7;
	//bool b1 = (cv1 == i64_a);
	//bool b2 = (i64_a == cv1);
	//int32_t i32_a = 7;
	//bool b3 = (cv1 == i32_a);
	//bool b4 = (i32_a == cv1);
}
