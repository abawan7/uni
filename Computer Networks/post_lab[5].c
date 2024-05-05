
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void parse(const char *line, long long int *user, long long int *nice, long long int *system, long long int *idle) {
    const char *token = strtok((char *)line, " ");
    token = strtok(NULL, " ");
    
 
    sscanf(token, "%lld %lld %lld %lld %lld", user, nice, system, idle);
}

int main() {
    char line[256];
    long long int user1, nice1, system1, idle1;
    long long int user2, nice2, system2, idle2;
    double cpu_utilization;

    FILE *stat= fopen("/proc/stat", "r");
    if (stat==NULL) {
        perror("Failed to open file");
        return 1;
    }
    fgets(line, sizeof(line), stat_file);
    parse(line, &user1, &nice1, &system1, &idle1);

    sleep(1);

    rewind(stat_file);
    fgets(line, sizeof(line), stat_file);
    parse(line, &user2, &nice2, &system2, &idle2);

    long long int cpu1 = user1 + nice1 + system1 + idle1;
    long long int cpu2 = user2 + nice2 + system2 + idle2;
    long long int idle_time = idle2 - idle1;
    long long int diff = cpu2 - cpu1;

    cpu_utilization = 100.0 * (1.0 - (double)idle_time / diff);

    printf("Average CPU Utilization: %.2lf%%\n", avg_utilization);

    fclose(stat);

    return 0;
}
