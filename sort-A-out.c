//Second Program (reader)
#include <sort-A.h>

//Initialize Queue Structure
struct msg_buff {
	long msg_type;
	char msg_txt[100];
} message;

int main()
{
	key_t key;

	//Generate Key
	key = ftok("sort", 01);

	//Create Queue and Return Id
	msgid = msgget(key, 0777 | IPC_Creat);

	//Receive Message

	msgrcv(msgid, &message, sizeof(message), 1, 0);

	//Display Message 
	printf("Data Recieved: %d /n", message.msg_txt);

	//Destroy Queue
	msgctl(msgid, IPC_RMID, NULL);

	return 0;

}