// Hardware Dependent Variables
// The values below works well with Syma X5SW

#define I2CBUS_NUM 1
#define I2C_ADDR   0x60


#define UPDOWN_GPIO 23
#define UPDOWN_ACTIVE LOW

#define ROTATE_GPIO 24
#define ROTATE_ACTIVE LOW

#define FB_GPIO 25
#define FB_ACTIVE HIGH

#define LR_GPIO 12
#define LR_ACTIVE HIGH

// For signal smoothing
#define SIGNAL_STEP 0.5f
// for usleep, in nm
#define SIGNAL_INTERVAL 10000

