@@ Abdelrahman Kamal (learn-in-depth).

.global reset	@@ global section

@@ reset section to initialize the stack pointer, then call main.
reset:
	ldr sp, = stack_top
	bl main


stop:
	b stop


