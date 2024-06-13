{ pkgs }: {
	deps = [
   pkgs.openssl
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}