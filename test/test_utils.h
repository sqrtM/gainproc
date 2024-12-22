#define COLOR_RESET "\033[0m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_YELLOW "\033[33m"

#define RIGHT_ARROW "\u2192" // →
#define LEFT_ARROW "\u2190" // ←
#define UP_ARROW "\u2191" // ↑
#define DOWN_ARROW "\u2193" // ↓
#define CHECK_MARK "\u2714" // ✔
#define CROSS_MARK "\u2716"  // ✖
#define INFO "\u2139" // ℹ
#define WARNING "\u26A0" // ⚠
#define SUN "\u2600"
#define CLOUD "\u2601"

void print_ok(const char* test);
void print_ko(const char* test, const char* message);
void print_row_of_suns();
void print_init_test_message();
void print_test_success();
void print_test_failure();
