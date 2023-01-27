#include <iostream>
#include <thread>
#include "Ringbuffer.h"

//En tråd for å lese fra tastaturet
//En tråd for å skrive til ringbufferet
//En tråd for å lese fra ringbufferet

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