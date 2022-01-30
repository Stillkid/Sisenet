#include "Message.h"

bool Message::add_serialization(const unsigned int message_content_type) {
	for (unsigned char i = 0; i != sizeof(message_structure); i++) {
		if (message_structure[i] == MESSAGE_CONTENTS_TYPE_EMPTY) {
			message_structure[i] = (MESSAGE_CONTENT_TYPE)message_content_type;
			return true;
		}
	}
	return false;
}

void Message::set_id(const unsigned char message_id) {
	this->message_id = message_id;
}

bool Message::serialize_uint() {
	return add_serialization(MESSAGE_CONTENTS_TYPE_UINT);
}

bool Message::serialize_int() {
	return add_serialization(MESSAGE_CONTENTS_TYPE_INT);
}

bool Message::serialize_float() {
	return add_serialization(MESSAGE_CONTENTS_TYPE_FLOAT);
}

bool Message::serialize_string() {
	return add_serialization(MESSAGE_CONTENTS_TYPE_STRING);
}