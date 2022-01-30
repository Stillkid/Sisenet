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

	bool add_serialization(unsigned int message_content_type) {
		for (unsigned char i = 0; i != sizeof(message_structure); i++) {
			if (message_structure[i] == MESSAGE_CONTENTS_TYPE_EMPTY) {
				message_structure[i] = (MESSAGE_CONTENT_TYPE) message_content_type;
				return true;
			}
		}
		return false;
	}
public:
	Message() {
		message_id = 0;
		for (unsigned char i = 0; i != sizeof(message_structure); i++)
			message_structure[i] = MESSAGE_CONTENTS_TYPE_EMPTY;
	}

	void set_id(unsigned char message_id) {
		this->message_id = message_id;
	}

	bool serialize_uint() {
		return add_serialization(MESSAGE_CONTENTS_TYPE_UINT);
	}

	bool serialize_int() {
		return add_serialization(MESSAGE_CONTENTS_TYPE_INT);
	}

	bool serialize_float() {
		return add_serialization(MESSAGE_CONTENTS_TYPE_FLOAT);
	}

	bool serialize_string() {
		return add_serialization(MESSAGE_CONTENTS_TYPE_STRING);
	}
};