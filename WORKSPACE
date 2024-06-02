workspace(name = "Cpp-Core")

# Fetches are order-independent, so we declare those first.
# All http_archive, http_file, etc. rules should be in the repositories.bzl file.
# DO NOT load those functions here in WORKSPACE.
load("//configurations:repositories.bzl", "fetch_deps")

fetch_deps()

load("@aspect_gcc_toolchain//toolchain:repositories.bzl", "gcc_toolchain_dependencies")

gcc_toolchain_dependencies()

load("@aspect_gcc_toolchain//toolchain:defs.bzl", "gcc_register_toolchain", "ARCHS")

gcc_register_toolchain(
    name = "gcc_toolchain_x86_64",
    target_arch = ARCHS.x86_64,
)
