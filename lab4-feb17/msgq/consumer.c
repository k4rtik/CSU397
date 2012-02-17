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

int main()
{
        int msgqid = create_msgq();

        int item = 0;

        while(1) {
                item = remove_item(shared_buffer);
                print_buffer(shared_buffer);
		sleep(1);
                consume_item(item);
        } 

        return 0;
}
