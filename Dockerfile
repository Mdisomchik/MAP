FROM gcc:latest
WORKDIR /usr/src/myapp
COPY . /usr/src/myapp
RUN gcc -o myapp Project.cpp -lstdc++
CMD ["./myapp"]
