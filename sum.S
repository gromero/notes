	.globl	sum
	.type   sum, @function

				# Archetypal prologue
sum:    mflr    %r0		# Get LR into r0.
	std     %r0, 16(%r1)	# Save LR in previous stack frame, offset SP+16.
	std 	%r31, -8(%r1)	# Save r31 in current stack frame, in "General Register Save Area".
	stdu	%r1, -96(%r1)	# Create the current stack. Size is 96 bytes, but could be anything aligned. 32 bytes are for non-optional offsets.
	mr 	%r31,  %r1	# Update r31, since it's used to load/store locals.

	li	%r9, 100	# Do some non-sense computation: input + 600; input = r3.
	std 	%r9, 40(%r1)	# Use stack to store our locals; In this case, current stack pointer + 40.
	li 	%r9, 200
	std 	%r9, 48(%r1)	# Store at current SP + 48.
	li 	%r9, 300
        add     %r3, %r3, %r9
	ld	%r9, 48(%r1)
        add     %r3, %r3, %r9
        ld      %r9, 40(%r1)
        add     %r3, %r3, %r9   # output = r3.

				# Archetypal epilogue
	addi 	%r1, %r31, 96	# Destroy current stack frame and go back to the previous one.
	ld	%r0, 16(%r1)	# Restore LR saved from previous frame into r0.
	mtlr	%r0		# Restore LR from r0.
	ld	%r31, -8(%r1)	# Restore r31 stored from the current frame.
	blr			# Return
