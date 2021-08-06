FROM gcc:11.1.0
COPY . /usr/src/imc
WORKDIR /usr/src/imc
RUN make
CMD ["./Visitor/visitor", "./Paper-Scissors-Rock/psr"]
