#include "shared.h"

void consume_item(int item) {
        ;
}

int remove_item(int semid, int *shared_buffer) {
        int index = get_buffer_size(shared_buffer) - 1;
        int item = shared_buffer[index];
        shared_buffer[index] = 0;
        return item;
}

int main()
{
        int *shared_buffer = create_shared_mem_buffer();
        int semid = create_semaphore_set();

        int item = 0;

        while(1) {
                semop(semid, &decFull, 1);
                semop(semid, &decMutex, 1);
                item = remove_item(semid, shared_buffer);
                print_buffer(shared_buffer);
                semop(semid, &incMutex, 1);
                semop(semid, &incEmpty, 1);
                consume_item(item);
        } 

        return 0;
}
