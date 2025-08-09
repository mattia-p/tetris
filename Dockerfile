# Use Ubuntu 22.04 as the base image
FROM ubuntu:22.04
# Prevent interactive prompts during package installation
ARG DEBIAN_FRONTEND=noninteractive

# Clean package lists, update, and install necessary packages
RUN apt-get clean && rm -rf /var/lib/apt/lists/* \
    && apt-get update \
    && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    clangd \
    gdb \
    git \
    g++ \
    sudo \
    libncurses5-dev \
    libncursesw5-dev
    

# Set the working directory inside the container
WORKDIR /tetris

# Copy your source code
COPY src/ .