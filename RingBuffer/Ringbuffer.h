#pragma once
#include <vector>

class Ringbuffer {
public:
	Ringbuffer(size_t size);
	bool put(char val);
	char get();
	char peek() const;
private:
	size_t m_size;
	uint8_t m_read;
	uint8_t m_write;
	std::vector<char> m_buffer;
	bool isEmpty();
	bool isFull();
};
