#include <linux/nfc/pn544_lge.h>

static struct pn544_i2c_platform_data nfc_pdata = {
        .irq_gpio = NFC_GPIO_IRQ,
        .ven_gpio = NFC_GPIO_VEN,
#if defined(CONFIG_MACH_LGE_CX2)
	.firm_gpio = NFC_GPIO_FIRM,
#else
        .firm_gpio = 0xFF,
#endif
};

#define NFC_I2C_BOARD_INFO						\
	{								\
    		I2C_BOARD_INFO(PN544_DRV_NAME, NFC_I2C_SLAVE_ADDR),	\
	    	.type = PN544_DRV_NAME,					\
	    	.irq = OMAP_GPIO_IRQ(NFC_GPIO_IRQ),			\
	    	.platform_data = &nfc_pdata,				\
	}


