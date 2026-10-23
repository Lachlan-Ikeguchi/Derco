# Derco

> "In mon derco marco axat ison"

> _May Marcos carry this out of my eye_

## Building

1. `make build`

The binaries are available at `./server/bin/derco-server` and `./client/bin/derco-client`.

## Idea

A performant modular CV pipeline described by a TOML file that can be configured
live.

## Overview

A server that owns a camera device and handles AWB and AE as specified in the
configuration TOML file. Hands over the captured frame to a round-robin worker
thread pool, and processes it according to the pipeline steps described
sequentially. The results of the processing feed into a shared result buffer in
JSON format served to clients with a request-response through a UNIX socket.

A client talks to the server through the UNIX socket, and can request a lean
result, server stats, debugging images of each steps of the pipeline, and read and
write server configuration. This project's own client hosts a web server that
provides an interface with a tab to configure the pipeline, see the server telemetry,
and see the results of the pipeline.

## Server

### Arguments

- `./path/to/config.toml`: specifies TOML configuration path (required).
- `--camera /dev/video0`: override TOML specified camera path.
- `--socket /tmp/derco-server.sock`: override TOML specified socket path.

## Client

### Arguments

- `--socket /tmp/derco-server.sock`: specifies the derco server socket (required).
- `--port 8080`: specifies web server port (default 8080).
