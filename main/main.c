#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "st7735.h"

st7735_t display;

void app_main(void) {
    // Inicialização (SCK=18, MOSI=22, CS=5, DC=2, RST=4)
    st7735_init(&display, SPI2_HOST, GPIO_NUM_18, GPIO_NUM_22, GPIO_NUM_5, GPIO_NUM_2, GPIO_NUM_4);

    // Preenche a tela inteira de preto
    st7735_fill_screen(&display, COLOR_BLACK);

    // Desenha um retângulo preenchido (ex: botão ou cabeçalho)
    st7735_fill_rect(&display, 5, 5, 118, 20, COLOR_BLUE);

    // Escreve texto
    st7735_draw_string(&display, 10, 10, "TFT LCD", COLOR_WHITE);
    st7735_draw_string(&display, 10, 35, "ST7735", COLOR_GREEN);

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
