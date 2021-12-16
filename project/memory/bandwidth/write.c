#include "./utils.h"

#define OP(i) arr[i] = rd;
#define ARR_LEN 1025

int main() {
    int *arr = malloc(ARR_LEN * sizeof(int));

    struct Timer timer;
    int rd = 8;

    obfs_memory

    sync_tsc();
    start_timer(&timer);

    OP(0)
    OP(16)
    OP(32)
    OP(48)
    OP(64)
    OP(80)
    OP(96)
    OP(112)
    OP(128)
    OP(144)
    OP(160)
    OP(176)
    OP(192)
    OP(208)
    OP(224)
    OP(240)
    OP(256)
    OP(272)
    OP(288)
    OP(304)
    OP(320)
    OP(336)
    OP(352)
    OP(368)
    OP(384)
    OP(400)
    OP(416)
    OP(432)
    OP(448)
    OP(464)
    OP(480)
    OP(496)
    OP(512)
    OP(528)
    OP(544)
    OP(560)
    OP(576)
    OP(592)
    OP(608)
    OP(624)
    OP(640)
    OP(656)
    OP(672)
    OP(688)
    OP(704)
    OP(720)
    OP(736)
    OP(752)
    OP(768)
    OP(784)
    OP(800)
    OP(816)
    OP(832)
    OP(848)
    OP(864)
    OP(880)
    OP(896)
    OP(912)
    OP(928)
    OP(944)
    OP(960)
    OP(976)
    OP(992)
    OP(1008)
    OP(1024)
    
    end_timer(&timer);
    sync_tsc();

    prt_speed(calc_diff(&timer));

    return 0;
}