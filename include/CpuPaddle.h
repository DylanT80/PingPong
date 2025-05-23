#ifndef CPUPADDLE_H
#define CPUPADDLE_H

#include "Paddle.h"

class CpuPaddle : public Paddle {
public:
    CpuPaddle(float x, float y, Color color, float width, float height);

    /**
     * @brief Updates paddle movements
     */
    void Update(float ball_y);
};

#endif // CPUPADDLE_H