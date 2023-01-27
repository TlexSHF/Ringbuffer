#include <iostream>
#include <thread>
#include "Ringbuffer.h"

//En tr�d for � lese fra tastaturet
//En tr�d for � skrive til ringbufferet
//En tr�d for � lese fra ringbufferet

void write(Ringbuffer& b) {
	//std::cout << "Writing";
	for(int c{'A'}; c <= 'Z'; ++c) {
		while(!b.put(c));
	}
}

void read(Ringbuffer& b) {
	//std::cout << "Reading";
	for (int i{ 0 }; i < 40; ++i) {
		char val{ 0 };
		do {
			val = b.get();
		} while (val == -1);

		std::cout << val << std::endl;
	}
}

int main() {

	Ringbuffer buffer(10);

	std::thread writer(write, std::ref(buffer));
	std::thread reader(read, std::ref(buffer));

	writer.join();
	reader.join();
}