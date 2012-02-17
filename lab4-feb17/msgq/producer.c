#include "shared.h"

void insert_item(int item, int *shared_buffer) {
        static int index = 0;
        shared_buffer[index] = item;
        index = (index+1) % BUFFER_SIZE;
}

int produce_item() {
        return 1;
}

int main()
{
        int msgqid = create_msgq();
        
        int *shared_buffer = msgp->mtext;

        clear_buffer(shared_buffer);

        int item;

        while(1) {
                item = produce_item();
		sleep(1);
                insert_item(item, shared_buffer);
                print_buffer(shared_buffer);
        }

        return 0;
}
