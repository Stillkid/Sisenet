#pragma once

enum MESSAGE_CONTENT_TYPE {
	MESSAGE_CONTENTS_TYPE_EMPTY = 0,
	MESSAGE_CONTENTS_TYPE_UINT  = 1,
	MESSAGE_CONTENTS_TYPE_INT   = 2,
	MESSAGE_CONTENTS_TYPE_FLOAT = 3,
	MESSAGE_CONTENTS_TYPE_STRING   = 4,
};

class Message {
private:
	unsigned char message_id;
	unsigned char message_structure[8];

	bool add_serialization(const unsigned int message_content_type);
public:
	Message() {
		message_id = 0;
		for (unsigned char i = 0; i != sizeof(message_structure); i++)
			message_structure[i] = MESSAGE_CONTENTS_TYPE_EMPTY;
	}

	void set_id(unsigned char message_id);

	bool serialize_uint();
	bool serialize_int();
	bool serialize_float();
	bool serialize_string();
};