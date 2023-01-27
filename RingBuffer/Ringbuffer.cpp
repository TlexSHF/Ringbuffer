#include <iostream>
#include "Ringbuffer.h"

Ringbuffer::Ringbuffer(size_t size) :
	m_size(size), m_read(0), m_write(0) {
	m_buffer = { std::vector<char>(size) };
	//std::vector<char> v(size);
}

bool Ringbuffer::put(char val) {
	if (isFull()) {
		//Writer must wait for reader
		return false;
	} else {
		//Writing to buffer & increments index
		m_buffer[m_write] = { val };
		++m_write %= m_size;
		return true;
	}
}

char Ringbuffer::get() {
	if (isEmpty()) {
		//Reader must wait for writer
		return -1;//what value could signify problem?
	} else {
		//Reading from buffer & increments index
		char val = peek();
		++m_read %= m_size;
		return val;
	}
}

char Ringbuffer::peek() const {
	return m_buffer[m_read];
}

bool Ringbuffer::isEmpty() {
	//Buffer is empty. Reader exceeded writer
	return m_read == m_write;
}

bool Ringbuffer::isFull() {
	//Buffer is at capacity. Writer reached reader-1 index
	return ((m_write + 1) % m_size) == m_read;
}
