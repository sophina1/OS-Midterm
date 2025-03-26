/*
(Question 1) For each of the following process state transition, say whether the 
transition is legal and how the transition occurs or why it cannot.

a. Change from thread state WAIT to thread state RUNNING
    This transition is not legal because a process in the WAIT state is waiting for
    an event to occur. Before it can run, it must first transition to the READY state
    once the event is resolved. The scheduler then selects it for execution, allowing
    it to transition from READY to RUNNING.

b. Change from thread state RUNNING to thread state WAIT
    This transition is legal. A process moves from RUNNNING to WAIT when it performs
    an operation that requires waiting, such as waiting for I/O, acquiring a lock, or
    waiting for another process to complete. During this time, it cannot continue
    execution until the required event occurs. 

c. Change from thread state READY to thread state WAIT
    This transition is not legal because a process in the READY state is waiting to
    be scheduled for execution but is not actively running. A process can only enter
    the WAIT state when it voluntarily yields control while executing. Therefore, it 
    must first transition to RUNNING before it can move to WAIT.
*/

/*
(Question 2) How many child processes are created upon execution of this program?
Consider the following piece of C code:
void main() {
    fork();
    fork();
    exit();
}
Each fork() doubles the number of processes. This first fork() creates
1 new child, making 2 processes total. the second fork() runs in both
processes, doubling them again to 4 processes total. Therefore, 3 child
processes are created in addition to the original process, thus the total
processes after executuion is 4. 
*/