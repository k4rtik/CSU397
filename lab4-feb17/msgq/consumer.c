#include "shared.h"

void consume_item(int item) {
        ;
}

int remove_item(int *shared_buffer) {
        static int index = 0;
        int item = shared_buffer[index];
        shared_buffer[index] = 0;
        index = (index+1) % BUFFER_SIZE;
        return item;
}

struct msgbuf {
	long mtype;       /* message type, must be > 0 */
        int mtext[BUFFER_SIZE];    /* message data */
} msgp;


int main()
{
        int msgqid = create_msgq();
        
        msgp.mtype = 1;
        
        int *shared_buffer = msgp.mtext;
        int item = 0;

        while(1) {
                item = remove_item(shared_buffer);
                if (msgrcv(msgqid, &msgp, BUFFER_SIZE, 1, 0) < 0) {
        		perror("msgrcvsnd: failed to receive");
        		exit(1);
        	}
        	print_buffer(shared_buffer);
		sleep(1);
                consume_item(item);
        } 

        return 0;
}
