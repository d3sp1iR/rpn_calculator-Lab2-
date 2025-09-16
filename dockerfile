FROM ubuntu:22.04 AS builder

RUN apt-get update && \
    apt-get install -y cmake g++ && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

# Ключевое: отключаем тесты полностью
RUN cmake -B build -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=OFF && \
    cmake --build build --target rpn_calculator --parallel 2

FROM ubuntu:22.04

RUN apt-get update && \
    apt-get install -y libstdc++6 && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY --from=builder /app/build/rpn_calculator .

ENTRYPOINT ["./rpn_calculator"]