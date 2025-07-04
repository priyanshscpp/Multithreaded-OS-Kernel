# Use an official Ubuntu base image 24 LTS 
FROM ubuntu:24.04


# Installing  dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    make \
    && rm -rf /var/lib/apt/lists/*

# Setting working directory
WORKDIR /app    

# Copy source code into the container
COPY . .

# Build the project
RUN make

# Command to run the application
CMD ["./lab4"]