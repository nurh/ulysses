.global _start

// This is where it enters the kernel proper
bl main

// When starting up, we want to disable every other CPU except CPU0



// Wait-for-event turns the CPU into low power mode, effectively disabling it.
halt:
	wfe
	b halt
