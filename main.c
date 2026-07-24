#define APP_START_ADDRESS 0x08010000U
uint32_t app_msp   = *(uint32_t *)APP_START_ADDRESS;
uint32_t app_reset = *(uint32_t *)(APP_START_ADDRESS + 4);

bool IsValidMSP(uint32_t msp)
{
    return (msp >= 0x20000000U) &&
           (msp <= 0x2001FFFFU);
}

bool IsValidResetHandler(uint32_t reset)
{
    reset &= ~1U;          // Clear Thumb bit

    return (reset >= APP_START_ADDRESS) &&
           (reset <= 0x0807FFFFU);
}

bool IsApplicationValid(void)
{
    uint32_t msp =
        *(uint32_t *)APP_START_ADDRESS;

    uint32_t reset =
        *(uint32_t *)(APP_START_ADDRESS + 4);

    return IsValidMSP(msp) &&
           IsValidResetHandler(reset);
}

typedef void (*AppEntry_t)(void);

void JumpToApplication(void)
{
    uint32_t app_msp =
        *(uint32_t *)APP_START_ADDRESS;

    uint32_t app_reset =
        *(uint32_t *)(APP_START_ADDRESS + 4);

    AppEntry_t AppEntry =
        (AppEntry_t)app_reset;

    __disable_irq();

    __set_MSP(app_msp);

    SCB->VTOR = APP_START_ADDRESS;

    AppEntry();
}

int main()
{
  return 0;
}
