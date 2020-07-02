//-----------------------------------------------------------------------------
// Jonathan Westhues, Aug 2005
// Gerhard de Koning Gans, April 2008, May 2011
//
// This code is licensed to you under the terms of the GNU GPL, version 2 or,
// at your option, any later version. See the LICENSE.txt file for the text of
// the license.
//-----------------------------------------------------------------------------
// Definitions internal to the app source.
//-----------------------------------------------------------------------------
#ifndef __ISO15693_H
#define __ISO15693_H

#include "common.h"
#include "pm3_cmd.h" // struct
								   

// Delays in SSP_CLK ticks.
// SSP_CLK runs at 13,56MHz / 32 = 423.75kHz when simulating a tag
#define DELAY_ISO15693_VCD_TO_VICC_SIM     132  // 132/423.75kHz = 311.5us from end of command EOF to start of tag response

//SSP_CLK runs at 13.56MHz / 4 = 3,39MHz when acting as reader. All values should be multiples of 16
#define DELAY_ISO15693_VCD_TO_VICC_READER 1056 // 1056/3,39MHz = 311.5us from end of command EOF to start of tag response
#define DELAY_ISO15693_VICC_TO_VCD_READER 1024 // 1024/3.39MHz = 302.1us between end of tag response and next reader command


void RecordRawAdcSamplesIso15693(void);
void AcquireRawAdcSamplesIso15693(void);
void ReaderIso15693(uint32_t parameter); // Simulate an ISO15693 reader - greg
void SimTagIso15693(uint8_t *uid); // simulate an ISO15693 tag - greg
void BruteforceIso15693Afi(uint32_t speed); // find an AFI of a tag - atrox
void DirectTag15693Command(uint32_t datalen, uint32_t speed, uint32_t recv, uint8_t *data); // send arbitrary commands from CLI - atrox
void Iso15693InitReader(void);

void SniffIso15693(uint8_t jam_search_len, uint8_t *jam_search_string);

int SendDataTag(uint8_t *send, int sendlen, bool init, bool speed_fast, uint8_t *recv, 
                uint16_t max_recv_len, uint32_t start_time, uint16_t timeout, uint32_t *eof_time);
                
int SendDataTagEOF(uint8_t *recv, uint16_t max_recv_len, uint32_t start_time, uint16_t timeout, uint32_t *eof_time);

void SetTag15693Uid(uint8_t *uid);
#endif
