#include "shared.h"

void insert_item(int item, int *shared_buffer) {
        int index = get_buffer_size(shared_buffer);
        shared_buffer[index] = item; 
}

int produce_item() {
        return 1;
}

int main()
{
        int *shared_buffer = create_shared_mem_buffer();
        int semid = create_semaphore_set();

        clear_buffer(shared_buffer);

        int item;

        while(1) {
                item = produce_item();
                
                semop(semid, &decEmpty, 1);
                semop(semid, &decMutex, 1);
                insert_item(item, shared_buffer);
                print_buffer(shared_buffer);
                semop(semid, &incMutex, 1);
                semop(semid, &incFull, 1);
        }

        return 0;
}
