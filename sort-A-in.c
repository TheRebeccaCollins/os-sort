//First Program (writer) 
#include <sort-A.h>
// Initialize Queue Structure
struct msg_buff {
	long msg_type;
	char msg_txt[100];
} message;

int main()
{
	key_t key;
	int msgid;

	//Generate Key
	key = ftok("sort", 01);

	//Create Queue and Return Id
	msgid = msgget(key, 0777 | IPC_CREAT);
	message.msgtype = 1;
	//Read Integers from stdin to Array
	printf("Enter 16 numbers: ");
	for(int i=0; i<16; i++){
		scanf("%d", &message.msg_txt[i]);}
	//Print Integers in origional order to stdout
	for(int i=0; i<16; i++) {
	printf("%d ", &message.msg_txt[i]);}
	//Bubblesort the Array 
	void swap(int* xp, int* yp) {
		int temp = *xp;
		*xp = *yp;
		*yp = temp; 
	}
	void bubbleSort(&message.msg_txt, int n) {
		int i, j;
		for (i = 0, i < n - 1; i++)
			for(j = 0; i < n -i -1; j++)
				if (&message.msg_txt[j] > &message.msg_txt[j + 1])
					swap(&message.msg_txt[j], &message.msg_txt[j + 1]);

	//Send Message
	msgsnd(msgid, &message, sizeof(message), 0);

	//printf("Numbers sent: %d \n", message.msg_txt);

	return 0;
}