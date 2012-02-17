#include "shared.h"

void insert_item(int item, int *shared_buffer) {
        static int index = 0;
        shared_buffer[index] = item;
        index = (index+1) % BUFFER_SIZE;
}

int produce_item() {
        return 1;
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

        int item;

        while(1) {
                item = produce_item();
		sleep(1);
                insert_item(item, shared_buffer);
                print_buffer(shared_buffer);
                
                if (msgsnd(msgqid, &msgp, BUFFER_SIZE, IPC_NOWAIT) < 0) {
        		perror("msgsnd: failed to send");
        		exit(1);
        	}
        }

        return 0;
}
