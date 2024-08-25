{ pkgs ? import <nixpkgs> {} }:

let
  stdenv = pkgs.stdenv;
  gcc = pkgs.gcc;
  lib = pkgs.lib;
in
stdenv.mkDerivation {
  name = "CMS";

  # Specify your source files here
  src = ./src;

  # Compiler flags
  CXXFLAGS = "-std=c++23";

  # Linker flags (if any)
  LDFLAGS = "";

  buildInputs = [ gcc ];

  # Build command
  buildPhase = ''
    mkdir -p $out/bin
    g++ $CXXFLAGS -o $out/bin/output.exe $src/main.cpp $LDFLAGS
  '';

  # Optional install phase if you want to do something specific
  # installPhase = ''
  #   echo "Installation phase"
  # '';

  meta = with lib; {
    description = "CMS";
    license = licenses.mit;
    platforms = platforms.linux;
  };
}
