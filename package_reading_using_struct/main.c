/*
 * main.c
 *
 *  Created on: Oct 2, 2024
 *      Author: shazz
 */

#include <stdio.h>
#include <stdint.h>

struct Frame{
	uint8_t crc;
	uint8_t status;
	uint16_t payload;
	uint8_t bat;
	uint8_t sensor;
	uint8_t longAddress;
	uint8_t shortAddress;
	uint8_t addressMode;
};

void PrintFields(struct Frame *p_packet, uint32_t frame);

int main(){
	uint32_t packetValue;
	printf("Enter a 32 bit packet value: ");
	scanf("%X", &packetValue);
	struct Frame packet;


	PrintFields(&packet, packetValue);


	while(getchar()!='\n'){

	}
	getchar();

}

void PrintFields(struct Frame *p_packet, uint32_t frame){
	p_packet->crc = (uint8_t) (frame & 0x3);
	p_packet->status = (uint8_t) ((frame>>2) & 0x1);
	p_packet->payload = (uint16_t) ((frame>>3) & 0xfff);
	p_packet->bat = (uint8_t) ((frame>>15) & 0x7);
	p_packet->sensor = (uint8_t) ((frame>>18) & 0x7);
	p_packet->longAddress = (uint8_t) ((frame>>21) & 0xff);
	p_packet->shortAddress = (uint8_t) ((frame>>29) & 0x3);
	p_packet->addressMode = (uint8_t) ((frame>>31) & 0x1);

	printf("following are different segments of the packet\n");
	printf("crc				=%#x \n", p_packet->crc);
	printf("statue			=%#x \n", p_packet->status);
	printf("payload			=%#x \n", p_packet->payload);
	printf("bat				=%#x \n", p_packet->bat);
	printf("sensor			=%#x \n", p_packet->sensor);
	printf("longAddress		=%#x \n", p_packet->longAddress);
	printf("shortAddress	=%#x \n", p_packet->shortAddress);
	printf("addressMode		=%#x \n", p_packet->addressMode);
}

