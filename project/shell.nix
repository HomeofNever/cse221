with import <nixpkgs> { allowUnfree = true; };
stdenv.mkDerivation {
  name = "cse221-project";
  # nativeBuildInputs = [ cmake gcc ];
  buildInputs = [ 
    # General information collector
    pciutils dmidecode 
    # Complier
    cmake gcc valgrind gdb 
    # Utils
    git python3 
    # Network
    ncat
  ];
}
