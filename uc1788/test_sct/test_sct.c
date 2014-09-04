
int xxx = 111;
int aaa[131072] = {0xAAAABBBB};

void SystemInit(void)
{
}

int main(void)
{
    aaa[xxx] = 1;
    xxx = xxx + 1;
    return xxx + aaa[1];
}
