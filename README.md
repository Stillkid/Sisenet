SiSenet - A Simple and secure UDP networking library for fast-paced communication.  

What?

SiSenet is a library that is meant to be utilized in environments that require fast paced and reliable networking over datagram sockets without the "bloat"/un-wanted functionality of TCP.

The main priorities of this library are (in order):
- A minimal & efficient, easy to understand code-base.
- Reliability at high transfer speeds.
- Security (CURVE25519, optional signing for servers, etc)

Use cases may include:

- Multiplayer games.
- File-transfer protocols.
- Embedded networking.
- IoT device communication.
- Blockchains.

Anything really, its the internet!

Why?

Mainly because I think it would be fun to try, I as a developer think it would be a fun and interesting challenge.
I also believe there is a need for such a library to exist out there, fully opensourced & copy-lefted;
with ease of use and not so much complicated bs. 

As they say, "overengineered code for too many cases".
This is what i believe alot of code is, rather than keeping things simple and accurate, certain code tends to be too extendable.

How?

- A/multiple message(s) get(s) serialized into a Packet DWORD by DWORD.
- A packet compressed into its most efficient state as quickly as possible.
- All messages in a packet are encrypted.
- A packet header is generated based upon these messages and user specified requirements.
	
	[PACKET_CONNECT]
	- Shared CURVE25519 key.

	[PACKET_DISCONNECT]
	- IV for encryption.
	- A goodbye message.

	[PACKET_MESSAGE]
	- IV for encryption.
	- 4 bytes of a running hash value (Little Endian, used to see that all messages are accurately decrypted and everything is ok at all times):
		* Allows for acknowledgements and ordering, if all packets have been received this should be the same, if it isn't the same we resend packets.
		* We do not send the next packet until these match. This keeps both sides of communication accurate and safe.

- A packet gets sent at a dynamic keep-alive rate, dependent on data needs and user configuration (this also has a side effect of creating spoofed padded messages!)
- A packet is received.
- A packet has its header checked.
- A packet is decrypted.
- A packet is decompressed.
- A/multiple message(s) get(s) serialized out of a Packet DWORD by DWORD.

If the 4 running bytes dont match we do not dispatch a new packet, we just send the old one..

The continual dispatching of packets leads to packets being buffered up until a number of [USER CHOICE] packets are present,
after which point a disconnect will occur and have to be handled.

This also introduces the concept of flow control, as you MUST send packets one-by-one for every connection.
A receiver should be able to choose how often to process a packet, meaning if one is received it is simply ignored.
