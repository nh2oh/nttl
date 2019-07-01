#include "clamped_value.h"
#include <iostream>


// Static_casts
void nttl::f1() {
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
void nttl::f2() {
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

void nttl::f3() {
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



