#define NO_ERROR 0L

//
// MessageId: ERROR_INVALID_FUNCTION
//
// MessageText:
//
// Incorrect function.
//
#define ERROR_INVALID_FUNCTION           1L    // dderror

//
// MessageId: ERROR_FILE_NOT_FOUND
//
// MessageText:
//
// The system cannot find the file specified.
//
#define ERROR_FILE_NOT_FOUND             2L

//
// MessageId: ERROR_PATH_NOT_FOUND
//
// MessageText:
//
// The system cannot find the path specified.
//
#define ERROR_PATH_NOT_FOUND             3L

//
// MessageId: ERROR_TOO_MANY_OPEN_FILES
//
// MessageText:
//
// The system cannot open the file.
//
#define ERROR_TOO_MANY_OPEN_FILES        4L

//
// MessageId: ERROR_ACCESS_DENIED
//
// MessageText:
//
// Access is denied.
//
#define ERROR_ACCESS_DENIED              5L

//
// MessageId: ERROR_INVALID_HANDLE
//
// MessageText:
//
// The handle is invalid.
//
#define ERROR_INVALID_HANDLE             6L

//
// MessageId: ERROR_ARENA_TRASHED
//
// MessageText:
//
// The storage control blocks were destroyed.
//
#define ERROR_ARENA_TRASHED              7L

//
// MessageId: ERROR_NOT_ENOUGH_MEMORY
//
// MessageText:
//
// Not enough storage is available to process this command.
//
#define ERROR_NOT_ENOUGH_MEMORY          8L    // dderror

//
// MessageId: ERROR_INVALID_BLOCK
//
// MessageText:
//
// The storage control block address is invalid.
//
#define ERROR_INVALID_BLOCK              9L

//
// MessageId: ERROR_BAD_ENVIRONMENT
//
// MessageText:
//
// The environment is incorrect.
//
#define ERROR_BAD_ENVIRONMENT            10L

//
// MessageId: ERROR_BAD_FORMAT
//
// MessageText:
//
// An attempt was made to load a program with an incorrect format.
//
#define ERROR_BAD_FORMAT                 11L

//
// MessageId: ERROR_INVALID_ACCESS
//
// MessageText:
//
// The access code is invalid.
//
#define ERROR_INVALID_ACCESS             12L

//
// MessageId: ERROR_INVALID_DATA
//
// MessageText:
//
// The data is invalid.
//
#define ERROR_INVALID_DATA               13L

//
// MessageId: ERROR_OUTOFMEMORY
//
// MessageText:
//
// Not enough storage is available to complete this operation.
//
#define ERROR_OUTOFMEMORY                14L

//
// MessageId: ERROR_INVALID_DRIVE
//
// MessageText:
//
// The system cannot find the drive specified.
//
#define ERROR_INVALID_DRIVE              15L

//
// MessageId: ERROR_CURRENT_DIRECTORY
//
// MessageText:
//
// The directory cannot be removed.
//
#define ERROR_CURRENT_DIRECTORY          16L

//
// MessageId: ERROR_NOT_SAME_DEVICE
//
// MessageText:
//
// The system cannot move the file to a different disk drive.
//
#define ERROR_NOT_SAME_DEVICE            17L

//
// MessageId: ERROR_NO_MORE_FILES
//
// MessageText:
//
// There are no more files.
//
#define ERROR_NO_MORE_FILES              18L

//
// MessageId: ERROR_WRITE_PROTECT
//
// MessageText:
//
// The media is write protected.
//
#define ERROR_WRITE_PROTECT              19L

//
// MessageId: ERROR_BAD_UNIT
//
// MessageText:
//
// The system cannot find the device specified.
//
#define ERROR_BAD_UNIT                   20L

//
// MessageId: ERROR_NOT_READY
//
// MessageText:
//
// The device is not ready.
//
#define ERROR_NOT_READY                  21L

//
// MessageId: ERROR_BAD_COMMAND
//
// MessageText:
//
// The device does not recognize the command.
//
#define ERROR_BAD_COMMAND                22L

//
// MessageId: ERROR_CRC
//
// MessageText:
//
// Data error (cyclic redundancy check).
//
#define ERROR_CRC                        23L

//
// MessageId: ERROR_BAD_LENGTH
//
// MessageText:
//
// The program issued a command but the command length is incorrect.
//
#define ERROR_BAD_LENGTH                 24L

//
// MessageId: ERROR_SEEK
//
// MessageText:
//
// The drive cannot locate a specific area or track on the disk.
//
#define ERROR_SEEK                       25L

//
// MessageId: ERROR_NOT_DOS_DISK
//
// MessageText:
//
// The specified disk or diskette cannot be accessed.
//
#define ERROR_NOT_DOS_DISK               26L

//
// MessageId: ERROR_SECTOR_NOT_FOUND
//
// MessageText:
//
// The drive cannot find the sector requested.
//
#define ERROR_SECTOR_NOT_FOUND           27L

//
// MessageId: ERROR_OUT_OF_PAPER
//
// MessageText:
//
// The printer is out of paper.
//
#define ERROR_OUT_OF_PAPER               28L

//
// MessageId: ERROR_WRITE_FAULT
//
// MessageText:
//
// The system cannot write to the specified device.
//
#define ERROR_WRITE_FAULT                29L

//
// MessageId: ERROR_READ_FAULT
//
// MessageText:
//
// The system cannot read from the specified device.
//
#define ERROR_READ_FAULT                 30L

//
// MessageId: ERROR_GEN_FAILURE
//
// MessageText:
//
// A device attached to the system is not functioning.
//
#define ERROR_GEN_FAILURE                31L

//
// MessageId: ERROR_SHARING_VIOLATION
//
// MessageText:
//
// The process cannot access the file because it is being used by another process.
//
#define ERROR_SHARING_VIOLATION          32L

//
// MessageId: ERROR_LOCK_VIOLATION
//
// MessageText:
//
// The process cannot access the file because another process has locked a portion of the file.
//
#define ERROR_LOCK_VIOLATION             33L

//
// MessageId: ERROR_WRONG_DISK
//
// MessageText:
//
// The wrong diskette is in the drive.
// Insert %2 (Volume Serial Number: %3) into drive %1.
//
#define ERROR_WRONG_DISK                 34L

//
// MessageId: ERROR_SHARING_BUFFER_EXCEEDED
//
// MessageText:
//
// Too many files opened for sharing.
//
#define ERROR_SHARING_BUFFER_EXCEEDED    36L

//
// MessageId: ERROR_HANDLE_EOF
//
// MessageText:
//
// Reached the end of the file.
//
#define ERROR_HANDLE_EOF                 38L

//
// MessageId: ERROR_HANDLE_DISK_FULL
//
// MessageText:
//
// The disk is full.
//
#define ERROR_HANDLE_DISK_FULL           39L

//
// MessageId: ERROR_NOT_SUPPORTED
//
// MessageText:
//
// The request is not supported.
//
#define ERROR_NOT_SUPPORTED              50L

//
// MessageId: ERROR_REM_NOT_LIST
//
// MessageText:
//
// Windows cannot find the network path. Verify that the network path is correct and the destination computer is not busy or turned off. If Windows still cannot find the network path, contact your network administrator.
//
#define ERROR_REM_NOT_LIST               51L

//
// MessageId: ERROR_DUP_NAME
//
// MessageText:
//
// You were not connected because a duplicate name exists on the network. If joining a domain, go to System in Control Panel to change the computer name and try again.  If joining a workgroup, choose another workgroup name.
//
#define ERROR_DUP_NAME                   52L

//
// MessageId: ERROR_BAD_NETPATH
//
// MessageText:
//
// The network path was not found.
//
#define ERROR_BAD_NETPATH                53L

//
// MessageId: ERROR_NETWORK_BUSY
//
// MessageText:
//
// The network is busy.
//
#define ERROR_NETWORK_BUSY               54L

//
// MessageId: ERROR_DEV_NOT_EXIST
//
// MessageText:
//
// The specified network resource or device is no longer available.
//
#define ERROR_DEV_NOT_EXIST              55L    // dderror

//
// MessageId: ERROR_TOO_MANY_CMDS
//
// MessageText:
//
// The network BIOS command limit has been reached.
//
#define ERROR_TOO_MANY_CMDS              56L

//
// MessageId: ERROR_ADAP_HDW_ERR
//
// MessageText:
//
// A network adapter hardware error occurred.
//
#define ERROR_ADAP_HDW_ERR               57L

//
// MessageId: ERROR_BAD_NET_RESP
//
// MessageText:
//
// The specified server cannot perform the requested operation.
//
#define ERROR_BAD_NET_RESP               58L

//
// MessageId: ERROR_UNEXP_NET_ERR
//
// MessageText:
//
// An unexpected network error occurred.
//
#define ERROR_UNEXP_NET_ERR              59L

//
// MessageId: ERROR_BAD_REM_ADAP
//
// MessageText:
//
// The remote adapter is not compatible.
//
#define ERROR_BAD_REM_ADAP               60L

//
// MessageId: ERROR_PRINTQ_FULL
//
// MessageText:
//
// The printer queue is full.
//
#define ERROR_PRINTQ_FULL                61L

//
// MessageId: ERROR_NO_SPOOL_SPACE
//
// MessageText:
//
// Space to store the file waiting to be printed is not available on the server.
//
#define ERROR_NO_SPOOL_SPACE             62L

//
// MessageId: ERROR_PRINT_CANCELLED
//
// MessageText:
//
// Your file waiting to be printed was deleted.
//
#define ERROR_PRINT_CANCELLED            63L

//
// MessageId: ERROR_NETNAME_DELETED
//
// MessageText:
//
// The specified network name is no longer available.
//
#define ERROR_NETNAME_DELETED            64L

//
// MessageId: ERROR_NETWORK_ACCESS_DENIED
//
// MessageText:
//
// Network access is denied.
//
#define ERROR_NETWORK_ACCESS_DENIED      65L

//
// MessageId: ERROR_BAD_DEV_TYPE
//
// MessageText:
//
// The network resource type is not correct.
//
#define ERROR_BAD_DEV_TYPE               66L

//
// MessageId: ERROR_BAD_NET_NAME
//
// MessageText:
//
// The network name cannot be found.
//
#define ERROR_BAD_NET_NAME               67L

//
// MessageId: ERROR_TOO_MANY_NAMES
//
// MessageText:
//
// The name limit for the local computer network adapter card was exceeded.
//
#define ERROR_TOO_MANY_NAMES             68L

//
// MessageId: ERROR_TOO_MANY_SESS
//
// MessageText:
//
// The network BIOS session limit was exceeded.
//
#define ERROR_TOO_MANY_SESS              69L

//
// MessageId: ERROR_SHARING_PAUSED
//
// MessageText:
//
// The remote server has been paused or is in the process of being started.
//
#define ERROR_SHARING_PAUSED             70L

//
// MessageId: ERROR_REQ_NOT_ACCEP
//
// MessageText:
//
// No more connections can be made to this remote computer at this time because there are already as many connections as the computer can accept.
//
#define ERROR_REQ_NOT_ACCEP              71L

//
// MessageId: ERROR_REDIR_PAUSED
//
// MessageText:
//
// The specified printer or disk device has been paused.
//
#define ERROR_REDIR_PAUSED               72L

//
// MessageId: ERROR_FILE_EXISTS
//
// MessageText:
//
// The file exists.
//
#define ERROR_FILE_EXISTS                80L

//
// MessageId: ERROR_CANNOT_MAKE
//
// MessageText:
//
// The directory or file cannot be created.
//
#define ERROR_CANNOT_MAKE                82L

//
// MessageId: ERROR_FAIL_I24
//
// MessageText:
//
// Fail on INT 24.
//
#define ERROR_FAIL_I24                   83L

//
// MessageId: ERROR_OUT_OF_STRUCTURES
//
// MessageText:
//
// Storage to process this request is not available.
//
#define ERROR_OUT_OF_STRUCTURES          84L

//
// MessageId: ERROR_ALREADY_ASSIGNED
//
// MessageText:
//
// The local device name is already in use.
//
#define ERROR_ALREADY_ASSIGNED           85L

//
// MessageId: ERROR_INVALID_PASSWORD
//
// MessageText:
//
// The specified network password is not correct.
//
#define ERROR_INVALID_PASSWORD           86L

//
// MessageId: ERROR_INVALID_PARAMETER
//
// MessageText:
//
// The parameter is incorrect.
//
#define ERROR_INVALID_PARAMETER          87L    // dderror

//
// MessageId: ERROR_NET_WRITE_FAULT
//
// MessageText:
//
// A write fault occurred on the network.
//
#define ERROR_NET_WRITE_FAULT            88L

//
// MessageId: ERROR_NO_PROC_SLOTS
//
// MessageText:
//
// The system cannot start another process at this time.
//
#define ERROR_NO_PROC_SLOTS              89L

//
// MessageId: ERROR_TOO_MANY_SEMAPHORES
//
// MessageText:
//
// Cannot create another system semaphore.
//
#define ERROR_TOO_MANY_SEMAPHORES        100L

//
// MessageId: ERROR_EXCL_SEM_ALREADY_OWNED
//
// MessageText:
//
// The exclusive semaphore is owned by another process.
//
#define ERROR_EXCL_SEM_ALREADY_OWNED     101L

//
// MessageId: ERROR_SEM_IS_SET
//
// MessageText:
//
// The semaphore is set and cannot be closed.
//
#define ERROR_SEM_IS_SET                 102L

//
// MessageId: ERROR_TOO_MANY_SEM_REQUESTS
//
// MessageText:
//
// The semaphore cannot be set again.
//
#define ERROR_TOO_MANY_SEM_REQUESTS      103L

//
// MessageId: ERROR_INVALID_AT_INTERRUPT_TIME
//
// MessageText:
//
// Cannot request exclusive semaphores at interrupt time.
//
#define ERROR_INVALID_AT_INTERRUPT_TIME  104L

//
// MessageId: ERROR_SEM_OWNER_DIED
//
// MessageText:
//
// The previous ownership of this semaphore has ended.
//
#define ERROR_SEM_OWNER_DIED             105L

//
// MessageId: ERROR_SEM_USER_LIMIT
//
// MessageText:
//
// Insert the diskette for drive %1.
//
#define ERROR_SEM_USER_LIMIT             106L

//
// MessageId: ERROR_DISK_CHANGE
//
// MessageText:
//
// The program stopped because an alternate diskette was not inserted.
//
#define ERROR_DISK_CHANGE                107L

//
// MessageId: ERROR_DRIVE_LOCKED
//
// MessageText:
//
// The disk is in use or locked by another process.
//
#define ERROR_DRIVE_LOCKED               108L

//
// MessageId: ERROR_BROKEN_PIPE
//
// MessageText:
//
// The pipe has been ended.
//
#define ERROR_BROKEN_PIPE                109L

//
// MessageId: ERROR_OPEN_FAILED
//
// MessageText:
//
// The system cannot open the device or file specified.
//
#define ERROR_OPEN_FAILED                110L

//
// MessageId: ERROR_BUFFER_OVERFLOW
//
// MessageText:
//
// The file name is too long.
//
#define ERROR_BUFFER_OVERFLOW            111L

//
// MessageId: ERROR_DISK_FULL
//
// MessageText:
//
// There is not enough space on the disk.
//
#define ERROR_DISK_FULL                  112L

//
// MessageId: ERROR_NO_MORE_SEARCH_HANDLES
//
// MessageText:
//
// No more internal file identifiers available.
//
#define ERROR_NO_MORE_SEARCH_HANDLES     113L

//
// MessageId: ERROR_INVALID_TARGET_HANDLE
//
// MessageText:
//
// The target internal file identifier is incorrect.
//
#define ERROR_INVALID_TARGET_HANDLE      114L

//
// MessageId: ERROR_INVALID_CATEGORY
//
// MessageText:
//
// The IOCTL call made by the application program is not correct.
//
#define ERROR_INVALID_CATEGORY           117L

//
// MessageId: ERROR_INVALID_VERIFY_SWITCH
//
// MessageText:
//
// The verify-on-write switch parameter value is not correct.
//
#define ERROR_INVALID_VERIFY_SWITCH      118L

//
// MessageId: ERROR_BAD_DRIVER_LEVEL
//
// MessageText:
//
// The system does not support the command requested.
//
#define ERROR_BAD_DRIVER_LEVEL           119L

//
// MessageId: ERROR_CALL_NOT_IMPLEMENTED
//
// MessageText:
//
// This function is not supported on this system.
//
#define ERROR_CALL_NOT_IMPLEMENTED       120L

//
// MessageId: ERROR_SEM_TIMEOUT
//
// MessageText:
//
// The semaphore timeout period has expired.
//
#define ERROR_SEM_TIMEOUT                121L

//
// MessageId: ERROR_INSUFFICIENT_BUFFER
//
// MessageText:
//
// The data area passed to a system call is too small.
//
#define ERROR_INSUFFICIENT_BUFFER        122L    // dderror

//
// MessageId: ERROR_INVALID_NAME
//
// MessageText:
//
// The filename, directory name, or volume label syntax is incorrect.
//
#define ERROR_INVALID_NAME               123L    // dderror

//
// MessageId: ERROR_INVALID_LEVEL
//
// MessageText:
//
// The system call level is not correct.
//
#define ERROR_INVALID_LEVEL              124L

//
// MessageId: ERROR_NO_VOLUME_LABEL
//
// MessageText:
//
// The disk has no volume label.
//
#define ERROR_NO_VOLUME_LABEL            125L

//
// MessageId: ERROR_MOD_NOT_FOUND
//
// MessageText:
//
// The specified module could not be found.
//
#define ERROR_MOD_NOT_FOUND              126L

//
// MessageId: ERROR_PROC_NOT_FOUND
//
// MessageText:
//
// The specified procedure could not be found.
//
#define ERROR_PROC_NOT_FOUND             127L

//
// MessageId: ERROR_WAIT_NO_CHILDREN
//
// MessageText:
//
// There are no child processes to wait for.
//
#define ERROR_WAIT_NO_CHILDREN           128L

//
// MessageId: ERROR_CHILD_NOT_COMPLETE
//
// MessageText:
//
// The %1 application cannot be run in Win32 mode.
//
#define ERROR_CHILD_NOT_COMPLETE         129L

//
// MessageId: ERROR_DIRECT_ACCESS_HANDLE
//
// MessageText:
//
// Attempt to use a file handle to an open disk partition for an operation other than raw disk I/O.
//
#define ERROR_DIRECT_ACCESS_HANDLE       130L

//
// MessageId: ERROR_NEGATIVE_SEEK
//
// MessageText:
//
// An attempt was made to move the file pointer before the beginning of the file.
//
#define ERROR_NEGATIVE_SEEK              131L

//
// MessageId: ERROR_SEEK_ON_DEVICE
//
// MessageText:
//
// The file pointer cannot be set on the specified device or file.
//
#define ERROR_SEEK_ON_DEVICE             132L

//
// MessageId: ERROR_IS_JOIN_TARGET
//
// MessageText:
//
// A JOIN or SUBST command cannot be used for a drive that contains previously joined drives.
//
#define ERROR_IS_JOIN_TARGET             133L

//
// MessageId: ERROR_IS_JOINED
//
// MessageText:
//
// An attempt was made to use a JOIN or SUBST command on a drive that has already been joined.
//
#define ERROR_IS_JOINED                  134L

//
// MessageId: ERROR_IS_SUBSTED
//
// MessageText:
//
// An attempt was made to use a JOIN or SUBST command on a drive that has already been substituted.
//
#define ERROR_IS_SUBSTED                 135L

//
// MessageId: ERROR_NOT_JOINED
//
// MessageText:
//
// The system tried to delete the JOIN of a drive that is not joined.
//
#define ERROR_NOT_JOINED                 136L

//
// MessageId: ERROR_NOT_SUBSTED
//
// MessageText:
//
// The system tried to delete the substitution of a drive that is not substituted.
//
#define ERROR_NOT_SUBSTED                137L

//
// MessageId: ERROR_JOIN_TO_JOIN
//
// MessageText:
//
// The system tried to join a drive to a directory on a joined drive.
//
#define ERROR_JOIN_TO_JOIN               138L

//
// MessageId: ERROR_SUBST_TO_SUBST
//
// MessageText:
//
// The system tried to substitute a drive to a directory on a substituted drive.
//
#define ERROR_SUBST_TO_SUBST             139L

//
// MessageId: ERROR_JOIN_TO_SUBST
//
// MessageText:
//
// The system tried to join a drive to a directory on a substituted drive.
//
#define ERROR_JOIN_TO_SUBST              140L

//
// MessageId: ERROR_SUBST_TO_JOIN
//
// MessageText:
//
// The system tried to SUBST a drive to a directory on a joined drive.
//
#define ERROR_SUBST_TO_JOIN              141L

//
// MessageId: ERROR_BUSY_DRIVE
//
// MessageText:
//
// The system cannot perform a JOIN or SUBST at this time.
//
#define ERROR_BUSY_DRIVE                 142L

//
// MessageId: ERROR_SAME_DRIVE
//
// MessageText:
//
// The system cannot join or substitute a drive to or for a directory on the same drive.
//
#define ERROR_SAME_DRIVE                 143L

//
// MessageId: ERROR_DIR_NOT_ROOT
//
// MessageText:
//
// The directory is not a subdirectory of the root directory.
//
#define ERROR_DIR_NOT_ROOT               144L

//
// MessageId: ERROR_DIR_NOT_EMPTY
//
// MessageText:
//
// The directory is not empty.
//
#define ERROR_DIR_NOT_EMPTY              145L

//
// MessageId: ERROR_IS_SUBST_PATH
//
// MessageText:
//
// The path specified is being used in a substitute.
//
#define ERROR_IS_SUBST_PATH              146L

//
// MessageId: ERROR_IS_JOIN_PATH
//
// MessageText:
//
// Not enough resources are available to process this command.
//
#define ERROR_IS_JOIN_PATH               147L

//
// MessageId: ERROR_PATH_BUSY
//
// MessageText:
//
// The path specified cannot be used at this time.
//
#define ERROR_PATH_BUSY                  148L

//
// MessageId: ERROR_IS_SUBST_TARGET
//
// MessageText:
//
// An attempt was made to join or substitute a drive for which a directory on the drive is the target of a previous substitute.
//
#define ERROR_IS_SUBST_TARGET            149L

//
// MessageId: ERROR_SYSTEM_TRACE
//
// MessageText:
//
// System trace information was not specified in your CONFIG.SYS file, or tracing is disallowed.
//
#define ERROR_SYSTEM_TRACE               150L

//
// MessageId: ERROR_INVALID_EVENT_COUNT
//
// MessageText:
//
// The number of specified semaphore events for DosMuxSemWait is not correct.
//
#define ERROR_INVALID_EVENT_COUNT        151L

//
// MessageId: ERROR_TOO_MANY_MUXWAITERS
//
// MessageText:
//
// DosMuxSemWait did not execute; too many semaphores are already set.
//
#define ERROR_TOO_MANY_MUXWAITERS        152L

//
// MessageId: ERROR_INVALID_LIST_FORMAT
//
// MessageText:
//
// The DosMuxSemWait list is not correct.
//
#define ERROR_INVALID_LIST_FORMAT        153L

//
// MessageId: ERROR_LABEL_TOO_LONG
//
// MessageText:
//
// The volume label you entered exceeds the label character limit of the target file system.
//
#define ERROR_LABEL_TOO_LONG             154L

//
// MessageId: ERROR_TOO_MANY_TCBS
//
// MessageText:
//
// Cannot create another thread.
//
#define ERROR_TOO_MANY_TCBS              155L

//
// MessageId: ERROR_SIGNAL_REFUSED
//
// MessageText:
//
// The recipient process has refused the signal.
//
#define ERROR_SIGNAL_REFUSED             156L

//
// MessageId: ERROR_DISCARDED
//
// MessageText:
//
// The segment is already discarded and cannot be locked.
//
#define ERROR_DISCARDED                  157L

//
// MessageId: ERROR_NOT_LOCKED
//
// MessageText:
//
// The segment is already unlocked.
//
#define ERROR_NOT_LOCKED                 158L

//
// MessageId: ERROR_BAD_THREADID_ADDR
//
// MessageText:
//
// The address for the thread ID is not correct.
//
#define ERROR_BAD_THREADID_ADDR          159L

//
// MessageId: ERROR_BAD_ARGUMENTS
//
// MessageText:
//
// One or more arguments are not correct.
//
#define ERROR_BAD_ARGUMENTS              160L

//
// MessageId: ERROR_BAD_PATHNAME
//
// MessageText:
//
// The specified path is invalid.
//
#define ERROR_BAD_PATHNAME               161L

//
// MessageId: ERROR_SIGNAL_PENDING
//
// MessageText:
//
// A signal is already pending.
//
#define ERROR_SIGNAL_PENDING             162L

//
// MessageId: ERROR_MAX_THRDS_REACHED
//
// MessageText:
//
// No more threads can be created in the system.
//
#define ERROR_MAX_THRDS_REACHED          164L

//
// MessageId: ERROR_LOCK_FAILED
//
// MessageText:
//
// Unable to lock a region of a file.
//
#define ERROR_LOCK_FAILED                167L

//
// MessageId: ERROR_BUSY
//
// MessageText:
//
// The requested resource is in use.
//
#define ERROR_BUSY                       170L    // dderror

//
// MessageId: ERROR_CANCEL_VIOLATION
//
// MessageText:
//
// A lock request was not outstanding for the supplied cancel region.
//
#define ERROR_CANCEL_VIOLATION           173L

//
// MessageId: ERROR_ATOMIC_LOCKS_NOT_SUPPORTED
//
// MessageText:
//
// The file system does not support atomic changes to the lock type.
//
#define ERROR_ATOMIC_LOCKS_NOT_SUPPORTED 174L

//
// MessageId: ERROR_INVALID_SEGMENT_NUMBER
//
// MessageText:
//
// The system detected a segment number that was not correct.
//
#define ERROR_INVALID_SEGMENT_NUMBER     180L

//
// MessageId: ERROR_INVALID_ORDINAL
//
// MessageText:
//
// The operating system cannot run %1.
//
#define ERROR_INVALID_ORDINAL            182L

//
// MessageId: ERROR_ALREADY_EXISTS
//
// MessageText:
//
// Cannot create a file when that file already exists.
//
#define ERROR_ALREADY_EXISTS             183L

//
// MessageId: ERROR_INVALID_FLAG_NUMBER
//
// MessageText:
//
// The flag passed is not correct.
//
#define ERROR_INVALID_FLAG_NUMBER        186L

//
// MessageId: ERROR_SEM_NOT_FOUND
//
// MessageText:
//
// The specified system semaphore name was not found.
//
#define ERROR_SEM_NOT_FOUND              187L

//
// MessageId: ERROR_INVALID_STARTING_CODESEG
//
// MessageText:
//
// The operating system cannot run %1.
//
#define ERROR_INVALID_STARTING_CODESEG   188L

//
// MessageId: ERROR_INVALID_STACKSEG
//
// MessageText:
//
// The operating system cannot run %1.
//
#define ERROR_INVALID_STACKSEG           189L

//
// MessageId: ERROR_INVALID_MODULETYPE
//
// MessageText:
//
// The operating system cannot run %1.
//
#define ERROR_INVALID_MODULETYPE         190L

//
// MessageId: ERROR_INVALID_EXE_SIGNATURE
//
// MessageText:
//
// Cannot run %1 in Win32 mode.
//
#define ERROR_INVALID_EXE_SIGNATURE      191L

//
// MessageId: ERROR_EXE_MARKED_INVALID
//
// MessageText:
//
// The operating system cannot run %1.
//
#define ERROR_EXE_MARKED_INVALID         192L

//
// MessageId: ERROR_BAD_EXE_FORMAT
//
// MessageText:
//
// %1 is not a valid Win32 application.
//
#define ERROR_BAD_EXE_FORMAT             193L

//
// MessageId: ERROR_ITERATED_DATA_EXCEEDS_64k
//
// MessageText:
//
// The operating system cannot run %1.
//
#define ERROR_ITERATED_DATA_EXCEEDS_64k  194L

//
// MessageId: ERROR_INVALID_MINALLOCSIZE
//
// MessageText:
//
// The operating system cannot run %1.
//
#define ERROR_INVALID_MINALLOCSIZE       195L

//
// MessageId: ERROR_DYNLINK_FROM_INVALID_RING
//
// MessageText:
//
// The operating system cannot run this application program.
//
#define ERROR_DYNLINK_FROM_INVALID_RING  196L

//
// MessageId: ERROR_IOPL_NOT_ENABLED
//
// MessageText:
//
// The operating system is not presently configured to run this application.
//
#define ERROR_IOPL_NOT_ENABLED           197L

//
// MessageId: ERROR_INVALID_SEGDPL
//
// MessageText:
//
// The operating system cannot run %1.
//
#define ERROR_INVALID_SEGDPL             198L

//
// MessageId: ERROR_AUTODATASEG_EXCEEDS_64k
//
// MessageText:
//
// The operating system cannot run this application program.
//
#define ERROR_AUTODATASEG_EXCEEDS_64k    199L

//
// MessageId: ERROR_RING2SEG_MUST_BE_MOVABLE
//
// MessageText:
//
// The code segment cannot be greater than or equal to 64K.
//
#define ERROR_RING2SEG_MUST_BE_MOVABLE   200L

//
// MessageId: ERROR_RELOC_CHAIN_XEEDS_SEGLIM
//
// MessageText:
//
// The operating system cannot run %1.
//
#define ERROR_RELOC_CHAIN_XEEDS_SEGLIM   201L

//
// MessageId: ERROR_INFLOOP_IN_RELOC_CHAIN
//
// MessageText:
//
// The operating system cannot run %1.
//
#define ERROR_INFLOOP_IN_RELOC_CHAIN     202L

//
// MessageId: ERROR_ENVVAR_NOT_FOUND
//
// MessageText:
//
// The system could not find the environment option that was entered.
//
#define ERROR_ENVVAR_NOT_FOUND           203L

//
// MessageId: ERROR_NO_SIGNAL_SENT
//
// MessageText:
//
// No process in the command subtree has a signal handler.
//
#define ERROR_NO_SIGNAL_SENT             205L

//
// MessageId: ERROR_FILENAME_EXCED_RANGE
//
// MessageText:
//
// The filename or extension is too long.
//
#define ERROR_FILENAME_EXCED_RANGE       206L

//
// MessageId: ERROR_RING2_STACK_IN_USE
//
// MessageText:
//
// The ring 2 stack is in use.
//
#define ERROR_RING2_STACK_IN_USE         207L

//
// MessageId: ERROR_META_EXPANSION_TOO_LONG
//
// MessageText:
//
// The global filename characters, * or ?, are entered incorrectly or too many global filename characters are specified.
//
#define ERROR_META_EXPANSION_TOO_LONG    208L

//
// MessageId: ERROR_INVALID_SIGNAL_NUMBER
//
// MessageText:
//
// The signal being posted is not correct.
//
#define ERROR_INVALID_SIGNAL_NUMBER      209L

//
// MessageId: ERROR_THREAD_1_INACTIVE
//
// MessageText:
//
// The signal handler cannot be set.
//
#define ERROR_THREAD_1_INACTIVE          210L

//
// MessageId: ERROR_LOCKED
//
// MessageText:
//
// The segment is locked and cannot be reallocated.
//
#define ERROR_LOCKED                     212L

//
// MessageId: ERROR_TOO_MANY_MODULES
//
// MessageText:
//
// Too many dynamic-link modules are attached to this program or dynamic-link module.
//
#define ERROR_TOO_MANY_MODULES           214L

//
// MessageId: ERROR_NESTING_NOT_ALLOWED
//
// MessageText:
//
// Cannot nest calls to LoadModule.
//
#define ERROR_NESTING_NOT_ALLOWED        215L

//
// MessageId: ERROR_EXE_MACHINE_TYPE_MISMATCH
//
// MessageText:
//
// This version of %1 is not compatible with the version of Windows you're running. Check your computer's system information to see whether you need a x86 (32-bit) or x64 (64-bit) version of the program, and then contact the software publisher.
//
#define ERROR_EXE_MACHINE_TYPE_MISMATCH  216L

//
// MessageId: ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY
//
// MessageText:
//
// The image file %1 is signed, unable to modify.
//
#define ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY 217L

//
// MessageId: ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY
//
// MessageText:
//
// The image file %1 is strong signed, unable to modify.
//
#define ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY 218L

//
// MessageId: ERROR_FILE_CHECKED_OUT
//
// MessageText:
//
// This file is checked out or locked for editing by another user.
//
#define ERROR_FILE_CHECKED_OUT           220L

//
// MessageId: ERROR_CHECKOUT_REQUIRED
//
// MessageText:
//
// The file must be checked out before saving changes.
//
#define ERROR_CHECKOUT_REQUIRED          221L

//
// MessageId: ERROR_BAD_FILE_TYPE
//
// MessageText:
//
// The file type being saved or retrieved has been blocked.
//
#define ERROR_BAD_FILE_TYPE              222L

//
// MessageId: ERROR_FILE_TOO_LARGE
//
// MessageText:
//
// The file size exceeds the limit allowed and cannot be saved.
//
#define ERROR_FILE_TOO_LARGE             223L

//
// MessageId: ERROR_FORMS_AUTH_REQUIRED
//
// MessageText:
//
// Access Denied. Before opening files in this location, you must first browse to the web site and select the option to login automatically.
//
#define ERROR_FORMS_AUTH_REQUIRED        224L

//
// MessageId: ERROR_VIRUS_INFECTED
//
// MessageText:
//
// Operation did not complete successfully because the file contains a virus.
//
#define ERROR_VIRUS_INFECTED             225L

//
// MessageId: ERROR_VIRUS_DELETED
//
// MessageText:
//
// This file contains a virus and cannot be opened. Due to the nature of this virus, the file has been removed from this location.
//
#define ERROR_VIRUS_DELETED              226L

//
// MessageId: ERROR_PIPE_LOCAL
//
// MessageText:
//
// The pipe is local.
//
#define ERROR_PIPE_LOCAL                 229L

//
// MessageId: ERROR_BAD_PIPE
//
// MessageText:
//
// The pipe state is invalid.
//
#define ERROR_BAD_PIPE                   230L

//
// MessageId: ERROR_PIPE_BUSY
//
// MessageText:
//
// All pipe instances are busy.
//
#define ERROR_PIPE_BUSY                  231L

//
// MessageId: ERROR_NO_DATA
//
// MessageText:
//
// The pipe is being closed.
//
#define ERROR_NO_DATA                    232L

//
// MessageId: ERROR_PIPE_NOT_CONNECTED
//
// MessageText:
//
// No process is on the other end of the pipe.
//
#define ERROR_PIPE_NOT_CONNECTED         233L

//
// MessageId: ERROR_MORE_DATA
//
// MessageText:
//
// More data is available.
//
#define ERROR_MORE_DATA                  234L    // dderror

//
// MessageId: ERROR_VC_DISCONNECTED
//
// MessageText:
//
// The session was canceled.
//
#define ERROR_VC_DISCONNECTED            240L

//
// MessageId: ERROR_INVALID_EA_NAME
//
// MessageText:
//
// The specified extended attribute name was invalid.
//
#define ERROR_INVALID_EA_NAME            254L

//
// MessageId: ERROR_EA_LIST_INCONSISTENT
//
// MessageText:
//
// The extended attributes are inconsistent.
//
#define ERROR_EA_LIST_INCONSISTENT       255L

//
// MessageId: WAIT_TIMEOUT
//
// MessageText:
//
// The wait operation timed out.
//
#define WAIT_TIMEOUT                     258L    // dderror

//
// MessageId: ERROR_NO_MORE_ITEMS
//
// MessageText:
//
// No more data is available.
//
#define ERROR_NO_MORE_ITEMS              259L

//
// MessageId: ERROR_CANNOT_COPY
//
// MessageText:
//
// The copy functions cannot be used.
//
#define ERROR_CANNOT_COPY                266L

//
// MessageId: ERROR_DIRECTORY
//
// MessageText:
//
// The directory name is invalid.
//
#define ERROR_DIRECTORY                  267L

//
// MessageId: ERROR_EAS_DIDNT_FIT
//
// MessageText:
//
// The extended attributes did not fit in the buffer.
//
#define ERROR_EAS_DIDNT_FIT              275L

//
// MessageId: ERROR_EA_FILE_CORRUPT
//
// MessageText:
//
// The extended attribute file on the mounted file system is corrupt.
//
#define ERROR_EA_FILE_CORRUPT            276L

//
// MessageId: ERROR_EA_TABLE_FULL
//
// MessageText:
//
// The extended attribute table file is full.
//
#define ERROR_EA_TABLE_FULL              277L

//
// MessageId: ERROR_INVALID_EA_HANDLE
//
// MessageText:
//
// The specified extended attribute handle is invalid.
//
#define ERROR_INVALID_EA_HANDLE          278L

//
// MessageId: ERROR_EAS_NOT_SUPPORTED
//
// MessageText:
//
// The mounted file system does not support extended attributes.
//
#define ERROR_EAS_NOT_SUPPORTED          282L

//
// MessageId: ERROR_NOT_OWNER
//
// MessageText:
//
// Attempt to release mutex not owned by caller.
//
#define ERROR_NOT_OWNER                  288L

//
// MessageId: ERROR_TOO_MANY_POSTS
//
// MessageText:
//
// Too many posts were made to a semaphore.
//
#define ERROR_TOO_MANY_POSTS             298L

//
// MessageId: ERROR_PARTIAL_COPY
//
// MessageText:
//
// Only part of a ReadProcessMemory or WriteProcessMemory request was completed.
//
#define ERROR_PARTIAL_COPY               299L

//
// MessageId: ERROR_OPLOCK_NOT_GRANTED
//
// MessageText:
//
// The oplock request is denied.
//
#define ERROR_OPLOCK_NOT_GRANTED         300L

//
// MessageId: ERROR_INVALID_OPLOCK_PROTOCOL
//
// MessageText:
//
// An invalid oplock acknowledgment was received by the system.
//
#define ERROR_INVALID_OPLOCK_PROTOCOL    301L

//
// MessageId: ERROR_DISK_TOO_FRAGMENTED
//
// MessageText:
//
// The volume is too fragmented to complete this operation.
//
#define ERROR_DISK_TOO_FRAGMENTED        302L

//
// MessageId: ERROR_DELETE_PENDING
//
// MessageText:
//
// The file cannot be opened because it is in the process of being deleted.
//
#define ERROR_DELETE_PENDING             303L

//
// MessageId: ERROR_MR_MID_NOT_FOUND
//
// MessageText:
//
// The system cannot find message text for message number 0x%1 in the message file for %2.
//
#define ERROR_MR_MID_NOT_FOUND           317L

//
// MessageId: ERROR_SCOPE_NOT_FOUND
//
// MessageText:
//
// The scope specified was not found.
//
#define ERROR_SCOPE_NOT_FOUND            318L

//
// MessageId: ERROR_FAIL_NOACTION_REBOOT
//
// MessageText:
//
// No action was taken as a system reboot is required.
//
#define ERROR_FAIL_NOACTION_REBOOT       350L

//
// MessageId: ERROR_FAIL_SHUTDOWN
//
// MessageText:
//
// The shutdown operation failed.
//
#define ERROR_FAIL_SHUTDOWN              351L

//
// MessageId: ERROR_FAIL_RESTART
//
// MessageText:
//
// The restart operation failed.
//
#define ERROR_FAIL_RESTART               352L

//
// MessageId: ERROR_MAX_SESSIONS_REACHED
//
// MessageText:
//
// The maximum number of sessions has been reached.
//
#define ERROR_MAX_SESSIONS_REACHED       353L

//
// MessageId: ERROR_THREAD_MODE_ALREADY_BACKGROUND
//
// MessageText:
//
// The thread is already in background processing mode.
//
#define ERROR_THREAD_MODE_ALREADY_BACKGROUND 400L

//
// MessageId: ERROR_THREAD_MODE_NOT_BACKGROUND
//
// MessageText:
//
// The thread is not in background processing mode.
//
#define ERROR_THREAD_MODE_NOT_BACKGROUND 401L

//
// MessageId: ERROR_PROCESS_MODE_ALREADY_BACKGROUND
//
// MessageText:
//
// The process is already in background processing mode.
//
#define ERROR_PROCESS_MODE_ALREADY_BACKGROUND 402L

//
// MessageId: ERROR_PROCESS_MODE_NOT_BACKGROUND
//
// MessageText:
//
// The process is not in background processing mode.
//
#define ERROR_PROCESS_MODE_NOT_BACKGROUND 403L

//
// MessageId: ERROR_INVALID_ADDRESS
//
// MessageText:
//
// Attempt to access invalid address.
//
#define ERROR_INVALID_ADDRESS            487L

//
// MessageId: ERROR_USER_PROFILE_LOAD
//
// MessageText:
//
// User profile cannot be loaded.
//
#define ERROR_USER_PROFILE_LOAD          500L

//
// MessageId: ERROR_ARITHMETIC_OVERFLOW
//
// MessageText:
//
// Arithmetic result exceeded 32 bits.
//
#define ERROR_ARITHMETIC_OVERFLOW        534L

//
// MessageId: ERROR_PIPE_CONNECTED
//
// MessageText:
//
// There is a process on other end of the pipe.
//
#define ERROR_PIPE_CONNECTED             535L

//
// MessageId: ERROR_PIPE_LISTENING
//
// MessageText:
//
// Waiting for a process to open the other end of the pipe.
//
#define ERROR_PIPE_LISTENING             536L

//
// MessageId: ERROR_VERIFIER_STOP
//
// MessageText:
//
// Application verifier has found an error in the current process.
//
#define ERROR_VERIFIER_STOP              537L

//
// MessageId: ERROR_ABIOS_ERROR
//
// MessageText:
//
// An error occurred in the ABIOS subsystem.
//
#define ERROR_ABIOS_ERROR                538L

//
// MessageId: ERROR_WX86_WARNING
//
// MessageText:
//
// A warning occurred in the WX86 subsystem.
//
#define ERROR_WX86_WARNING               539L

//
// MessageId: ERROR_WX86_ERROR
//
// MessageText:
//
// An error occurred in the WX86 subsystem.
//
#define ERROR_WX86_ERROR                 540L

//
// MessageId: ERROR_TIMER_NOT_CANCELED
//
// MessageText:
//
// An attempt was made to cancel or set a timer that has an associated APC and the subject thread is not the thread that originally set the timer with an associated APC routine.
//
#define ERROR_TIMER_NOT_CANCELED         541L

//
// MessageId: ERROR_UNWIND
//
// MessageText:
//
// Unwind exception code.
//
#define ERROR_UNWIND                     542L

//
// MessageId: ERROR_BAD_STACK
//
// MessageText:
//
// An invalid or unaligned stack was encountered during an unwind operation.
//
#define ERROR_BAD_STACK                  543L

//
// MessageId: ERROR_INVALID_UNWIND_TARGET
//
// MessageText:
//
// An invalid unwind target was encountered during an unwind operation.
//
#define ERROR_INVALID_UNWIND_TARGET      544L

//
// MessageId: ERROR_INVALID_PORT_ATTRIBUTES
//
// MessageText:
//
// Invalid Object Attributes specified to NtCreatePort or invalid Port Attributes specified to NtConnectPort
//
#define ERROR_INVALID_PORT_ATTRIBUTES    545L

//
// MessageId: ERROR_PORT_MESSAGE_TOO_LONG
//
// MessageText:
//
// Length of message passed to NtRequestPort or NtRequestWaitReplyPort was longer than the maximum message allowed by the port.
//
#define ERROR_PORT_MESSAGE_TOO_LONG      546L

//
// MessageId: ERROR_INVALID_QUOTA_LOWER
//
// MessageText:
//
// An attempt was made to lower a quota limit below the current usage.
//
#define ERROR_INVALID_QUOTA_LOWER        547L

//
// MessageId: ERROR_DEVICE_ALREADY_ATTACHED
//
// MessageText:
//
// An attempt was made to attach to a device that was already attached to another device.
//
#define ERROR_DEVICE_ALREADY_ATTACHED    548L

//
// MessageId: ERROR_INSTRUCTION_MISALIGNMENT
//
// MessageText:
//
// An attempt was made to execute an instruction at an unaligned address and the host system does not support unaligned instruction references.
//
#define ERROR_INSTRUCTION_MISALIGNMENT   549L

//
// MessageId: ERROR_PROFILING_NOT_STARTED
//
// MessageText:
//
// Profiling not started.
//
#define ERROR_PROFILING_NOT_STARTED      550L

//
// MessageId: ERROR_PROFILING_NOT_STOPPED
//
// MessageText:
//
// Profiling not stopped.
//
#define ERROR_PROFILING_NOT_STOPPED      551L

//
// MessageId: ERROR_COULD_NOT_INTERPRET
//
// MessageText:
//
// The passed ACL did not contain the minimum required information.
//
#define ERROR_COULD_NOT_INTERPRET        552L

//
// MessageId: ERROR_PROFILING_AT_LIMIT
//
// MessageText:
//
// The number of active profiling objects is at the maximum and no more may be started.
//
#define ERROR_PROFILING_AT_LIMIT         553L

//
// MessageId: ERROR_CANT_WAIT
//
// MessageText:
//
// Used to indicate that an operation cannot continue without blocking for I/O.
//
#define ERROR_CANT_WAIT                  554L

//
// MessageId: ERROR_CANT_TERMINATE_SELF
//
// MessageText:
//
// Indicates that a thread attempted to terminate itself by default (called NtTerminateThread with NULL) and it was the last thread in the current process.
//
#define ERROR_CANT_TERMINATE_SELF        555L

//
// MessageId: ERROR_UNEXPECTED_MM_CREATE_ERR
//
// MessageText:
//
// If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter.
// In this case information is lost, however, the filter correctly handles the exception.
//
#define ERROR_UNEXPECTED_MM_CREATE_ERR   556L

//
// MessageId: ERROR_UNEXPECTED_MM_MAP_ERROR
//
// MessageText:
//
// If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter.
// In this case information is lost, however, the filter correctly handles the exception.
//
#define ERROR_UNEXPECTED_MM_MAP_ERROR    557L

//
// MessageId: ERROR_UNEXPECTED_MM_EXTEND_ERR
//
// MessageText:
//
// If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter.
// In this case information is lost, however, the filter correctly handles the exception.
//
#define ERROR_UNEXPECTED_MM_EXTEND_ERR   558L

//
// MessageId: ERROR_BAD_FUNCTION_TABLE
//
// MessageText:
//
// A malformed function table was encountered during an unwind operation.
//
#define ERROR_BAD_FUNCTION_TABLE         559L

//
// MessageId: ERROR_NO_GUID_TRANSLATION
//
// MessageText:
//
// Indicates that an attempt was made to assign protection to a file system file or directory and one of the SIDs in the security descriptor could not be translated into a GUID that could be stored by the file system.
// This causes the protection attempt to fail, which may cause a file creation attempt to fail.
//
#define ERROR_NO_GUID_TRANSLATION        560L

//
// MessageId: ERROR_INVALID_LDT_SIZE
//
// MessageText:
//
// Indicates that an attempt was made to grow an LDT by setting its size, or that the size was not an even number of selectors.
//
#define ERROR_INVALID_LDT_SIZE           561L

//
// MessageId: ERROR_INVALID_LDT_OFFSET
//
// MessageText:
//
// Indicates that the starting value for the LDT information was not an integral multiple of the selector size.
//
#define ERROR_INVALID_LDT_OFFSET         563L

//
// MessageId: ERROR_INVALID_LDT_DESCRIPTOR
//
// MessageText:
//
// Indicates that the user supplied an invalid descriptor when trying to set up Ldt descriptors.
//
#define ERROR_INVALID_LDT_DESCRIPTOR     564L

//
// MessageId: ERROR_TOO_MANY_THREADS
//
// MessageText:
//
// Indicates a process has too many threads to perform the requested action. For example, assignment of a primary token may only be performed when a process has zero or one threads.
//
#define ERROR_TOO_MANY_THREADS           565L

//
// MessageId: ERROR_THREAD_NOT_IN_PROCESS
//
// MessageText:
//
// An attempt was made to operate on a thread within a specific process, but the thread specified is not in the process specified.
//
#define ERROR_THREAD_NOT_IN_PROCESS      566L

//
// MessageId: ERROR_PAGEFILE_QUOTA_EXCEEDED
//
// MessageText:
//
// Page file quota was exceeded.
//
#define ERROR_PAGEFILE_QUOTA_EXCEEDED    567L

//
// MessageId: ERROR_LOGON_SERVER_CONFLICT
//
// MessageText:
//
// The Netlogon service cannot start because another Netlogon service running in the domain conflicts with the specified role.
//
#define ERROR_LOGON_SERVER_CONFLICT      568L

//
// MessageId: ERROR_SYNCHRONIZATION_REQUIRED
//
// MessageText:
//
// The SAM database on a Windows Server is significantly out of synchronization with the copy on the Domain Controller. A complete synchronization is required.
//
#define ERROR_SYNCHRONIZATION_REQUIRED   569L

//
// MessageId: ERROR_NET_OPEN_FAILED
//
// MessageText:
//
// The NtCreateFile API failed. This error should never be returned to an application, it is a place holder for the Windows Lan Manager Redirector to use in its internal error mapping routines.
//
#define ERROR_NET_OPEN_FAILED            570L

//
// MessageId: ERROR_IO_PRIVILEGE_FAILED
//
// MessageText:
//
// {Privilege Failed}
// The I/O permissions for the process could not be changed.
//
#define ERROR_IO_PRIVILEGE_FAILED        571L

//
// MessageId: ERROR_CONTROL_C_EXIT
//
// MessageText:
//
// {Application Exit by CTRL+C}
// The application terminated as a result of a CTRL+C.
//
#define ERROR_CONTROL_C_EXIT             572L    // winnt

//
// MessageId: ERROR_MISSING_SYSTEMFILE
//
// MessageText:
//
// {Missing System File}
// The required system file %hs is bad or missing.
//
#define ERROR_MISSING_SYSTEMFILE         573L

//
// MessageId: ERROR_UNHANDLED_EXCEPTION
//
// MessageText:
//
// {Application Error}
// The exception %s (0x%08lx) occurred in the application at location 0x%08lx.
//
#define ERROR_UNHANDLED_EXCEPTION        574L

//
// MessageId: ERROR_APP_INIT_FAILURE
//
// MessageText:
//
// {Application Error}
// The application failed to initialize properly (0x%lx). Click OK to terminate the application.
//
#define ERROR_APP_INIT_FAILURE           575L

//
// MessageId: ERROR_PAGEFILE_CREATE_FAILED
//
// MessageText:
//
// {Unable to Create Paging File}
// The creation of the paging file %hs failed (%lx). The requested size was %ld.
//
#define ERROR_PAGEFILE_CREATE_FAILED     576L

//
// MessageId: ERROR_INVALID_IMAGE_HASH
//
// MessageText:
//
// Windows cannot verify the digital signature for this file. A recent hardware or software change might have installed a file that is signed incorrectly or damaged, or that might be malicious software from an unknown source.
//
#define ERROR_INVALID_IMAGE_HASH         577L

//
// MessageId: ERROR_NO_PAGEFILE
//
// MessageText:
//
// {No Paging File Specified}
// No paging file was specified in the system configuration.
//
#define ERROR_NO_PAGEFILE                578L

//
// MessageId: ERROR_ILLEGAL_FLOAT_CONTEXT
//
// MessageText:
//
// {EXCEPTION}
// A real-mode application issued a floating-point instruction and floating-point hardware is not present.
//
#define ERROR_ILLEGAL_FLOAT_CONTEXT      579L

//
// MessageId: ERROR_NO_EVENT_PAIR
//
// MessageText:
//
// An event pair synchronization operation was performed using the thread specific client/server event pair object, but no event pair object was associated with the thread.
//
#define ERROR_NO_EVENT_PAIR              580L

//
// MessageId: ERROR_DOMAIN_CTRLR_CONFIG_ERROR
//
// MessageText:
//
// A Windows Server has an incorrect configuration.
//
#define ERROR_DOMAIN_CTRLR_CONFIG_ERROR  581L

//
// MessageId: ERROR_ILLEGAL_CHARACTER
//
// MessageText:
//
// An illegal character was encountered. For a multi-byte character set this includes a lead byte without a succeeding trail byte. For the Unicode character set this includes the characters 0xFFFF and 0xFFFE.
//
#define ERROR_ILLEGAL_CHARACTER          582L

//
// MessageId: ERROR_UNDEFINED_CHARACTER
//
// MessageText:
//
// The Unicode character is not defined in the Unicode character set installed on the system.
//
#define ERROR_UNDEFINED_CHARACTER        583L

//
// MessageId: ERROR_FLOPPY_VOLUME
//
// MessageText:
//
// The paging file cannot be created on a floppy diskette.
//
#define ERROR_FLOPPY_VOLUME              584L

//
// MessageId: ERROR_BIOS_FAILED_TO_CONNECT_INTERRUPT
//
// MessageText:
//
// The system BIOS failed to connect a system interrupt to the device or bus for which the device is connected.
//
#define ERROR_BIOS_FAILED_TO_CONNECT_INTERRUPT 585L

//
// MessageId: ERROR_BACKUP_CONTROLLER
//
// MessageText:
//
// This operation is only allowed for the Primary Domain Controller of the domain.
//
#define ERROR_BACKUP_CONTROLLER          586L

//
// MessageId: ERROR_MUTANT_LIMIT_EXCEEDED
//
// MessageText:
//
// An attempt was made to acquire a mutant such that its maximum count would have been exceeded.
//
#define ERROR_MUTANT_LIMIT_EXCEEDED      587L

//
// MessageId: ERROR_FS_DRIVER_REQUIRED
//
// MessageText:
//
// A volume has been accessed for which a file system driver is required that has not yet been loaded.
//
#define ERROR_FS_DRIVER_REQUIRED         588L

//
// MessageId: ERROR_CANNOT_LOAD_REGISTRY_FILE
//
// MessageText:
//
// {Registry File Failure}
// The registry cannot load the hive (file):
// %hs
// or its log or alternate.
// It is corrupt, absent, or not writable.
//
#define ERROR_CANNOT_LOAD_REGISTRY_FILE  589L

//
// MessageId: ERROR_DEBUG_ATTACH_FAILED
//
// MessageText:
//
// {Unexpected Failure in DebugActiveProcess}
// An unexpected failure occurred while processing a DebugActiveProcess API request. You may choose OK to terminate the process, or Cancel to ignore the error.
//
#define ERROR_DEBUG_ATTACH_FAILED        590L

//
// MessageId: ERROR_SYSTEM_PROCESS_TERMINATED
//
// MessageText:
//
// {Fatal System Error}
// The %hs system process terminated unexpectedly with a status of 0x%08x (0x%08x 0x%08x).
// The system has been shut down.
//
#define ERROR_SYSTEM_PROCESS_TERMINATED  591L

//
// MessageId: ERROR_DATA_NOT_ACCEPTED
//
// MessageText:
//
// {Data Not Accepted}
// The TDI client could not handle the data received during an indication.
//
#define ERROR_DATA_NOT_ACCEPTED          592L

//
// MessageId: ERROR_VDM_HARD_ERROR
//
// MessageText:
//
// NTVDM encountered a hard error.
//
#define ERROR_VDM_HARD_ERROR             593L

//
// MessageId: ERROR_DRIVER_CANCEL_TIMEOUT
//
// MessageText:
//
// {Cancel Timeout}
// The driver %hs failed to complete a cancelled I/O request in the allotted time.
//
#define ERROR_DRIVER_CANCEL_TIMEOUT      594L

//
// MessageId: ERROR_REPLY_MESSAGE_MISMATCH
//
// MessageText:
//
// {Reply Message Mismatch}
// An attempt was made to reply to an LPC message, but the thread specified by the client ID in the message was not waiting on that message.
//
#define ERROR_REPLY_MESSAGE_MISMATCH     595L

//
// MessageId: ERROR_LOST_WRITEBEHIND_DATA
//
// MessageText:
//
// {Delayed Write Failed}
// Windows was unable to save all the data for the file %hs. The data has been lost.
// This error may be caused by a failure of your computer hardware or network connection. Please try to save this file elsewhere.
//
#define ERROR_LOST_WRITEBEHIND_DATA      596L

//
// MessageId: ERROR_CLIENT_SERVER_PARAMETERS_INVALID
//
// MessageText:
//
// The parameter(s) passed to the server in the client/server shared memory window were invalid. Too much data may have been put in the shared memory window.
//
#define ERROR_CLIENT_SERVER_PARAMETERS_INVALID 597L

//
// MessageId: ERROR_NOT_TINY_STREAM
//
// MessageText:
//
// The stream is not a tiny stream.
//
#define ERROR_NOT_TINY_STREAM            598L

//
// MessageId: ERROR_STACK_OVERFLOW_READ
//
// MessageText:
//
// The request must be handled by the stack overflow code.
//
#define ERROR_STACK_OVERFLOW_READ        599L

//
// MessageId: ERROR_CONVERT_TO_LARGE
//
// MessageText:
//
// Internal OFS status codes indicating how an allocation operation is handled. Either it is retried after the containing onode is moved or the extent stream is converted to a large stream.
//
#define ERROR_CONVERT_TO_LARGE           600L

//
// MessageId: ERROR_FOUND_OUT_OF_SCOPE
//
// MessageText:
//
// The attempt to find the object found an object matching by ID on the volume but it is out of the scope of the handle used for the operation.
//
#define ERROR_FOUND_OUT_OF_SCOPE         601L

//
// MessageId: ERROR_ALLOCATE_BUCKET
//
// MessageText:
//
// The bucket array must be grown. Retry transaction after doing so.
//
#define ERROR_ALLOCATE_BUCKET            602L

//
// MessageId: ERROR_MARSHALL_OVERFLOW
//
// MessageText:
//
// The user/kernel marshalling buffer has overflowed.
//
#define ERROR_MARSHALL_OVERFLOW          603L

//
// MessageId: ERROR_INVALID_VARIANT
//
// MessageText:
//
// The supplied variant structure contains invalid data.
//
#define ERROR_INVALID_VARIANT            604L

//
// MessageId: ERROR_BAD_COMPRESSION_BUFFER
//
// MessageText:
//
// The specified buffer contains ill-formed data.
//
#define ERROR_BAD_COMPRESSION_BUFFER     605L

//
// MessageId: ERROR_AUDIT_FAILED
//
// MessageText:
//
// {Audit Failed}
// An attempt to generate a security audit failed.
//
#define ERROR_AUDIT_FAILED               606L

//
// MessageId: ERROR_TIMER_RESOLUTION_NOT_SET
//
// MessageText:
//
// The timer resolution was not previously set by the current process.
//
#define ERROR_TIMER_RESOLUTION_NOT_SET   607L

//
// MessageId: ERROR_INSUFFICIENT_LOGON_INFO
//
// MessageText:
//
// There is insufficient account information to log you on.
//
#define ERROR_INSUFFICIENT_LOGON_INFO    608L

//
// MessageId: ERROR_BAD_DLL_ENTRYPOINT
//
// MessageText:
//
// {Invalid DLL Entrypoint}
// The dynamic link library %hs is not written correctly. The stack pointer has been left in an inconsistent state.
// The entrypoint should be declared as WINAPI or STDCALL. Select YES to fail the DLL load. Select NO to continue execution. Selecting NO may cause the application to operate incorrectly.
//
#define ERROR_BAD_DLL_ENTRYPOINT         609L

//
// MessageId: ERROR_BAD_SERVICE_ENTRYPOINT
//
// MessageText:
//
// {Invalid Service Callback Entrypoint}
// The %hs service is not written correctly. The stack pointer has been left in an inconsistent state.
// The callback entrypoint should be declared as WINAPI or STDCALL. Selecting OK will cause the service to continue operation. However, the service process may operate incorrectly.
//
#define ERROR_BAD_SERVICE_ENTRYPOINT     610L

//
// MessageId: ERROR_IP_ADDRESS_CONFLICT1
//
// MessageText:
//
// There is an IP address conflict with another system on the network
//
#define ERROR_IP_ADDRESS_CONFLICT1       611L

//
// MessageId: ERROR_IP_ADDRESS_CONFLICT2
//
// MessageText:
//
// There is an IP address conflict with another system on the network
//
#define ERROR_IP_ADDRESS_CONFLICT2       612L

//
// MessageId: ERROR_REGISTRY_QUOTA_LIMIT
//
// MessageText:
//
// {Low On Registry Space}
// The system has reached the maximum size allowed for the system part of the registry. Additional storage requests will be ignored.
//
#define ERROR_REGISTRY_QUOTA_LIMIT       613L

//
// MessageId: ERROR_NO_CALLBACK_ACTIVE
//
// MessageText:
//
// A callback return system service cannot be executed when no callback is active.
//
#define ERROR_NO_CALLBACK_ACTIVE         614L

//
// MessageId: ERROR_PWD_TOO_SHORT
//
// MessageText:
//
// The password provided is too short to meet the policy of your user account.
// Please choose a longer password.
//
#define ERROR_PWD_TOO_SHORT              615L

//
// MessageId: ERROR_PWD_TOO_RECENT
//
// MessageText:
//
// The policy of your user account does not allow you to change passwords too frequently.
// This is done to prevent users from changing back to a familiar, but potentially discovered, password.
// If you feel your password has been compromised then please contact your administrator immediately to have a new one assigned.
//
#define ERROR_PWD_TOO_RECENT             616L

//
// MessageId: ERROR_PWD_HISTORY_CONFLICT
//
// MessageText:
//
// You have attempted to change your password to one that you have used in the past.
// The policy of your user account does not allow this. Please select a password that you have not previously used.
//
#define ERROR_PWD_HISTORY_CONFLICT       617L

//
// MessageId: ERROR_UNSUPPORTED_COMPRESSION
//
// MessageText:
//
// The specified compression format is unsupported.
//
#define ERROR_UNSUPPORTED_COMPRESSION    618L

//
// MessageId: ERROR_INVALID_HW_PROFILE
//
// MessageText:
//
// The specified hardware profile configuration is invalid.
//
#define ERROR_INVALID_HW_PROFILE         619L

//
// MessageId: ERROR_INVALID_PLUGPLAY_DEVICE_PATH
//
// MessageText:
//
// The specified Plug and Play registry device path is invalid.
//
#define ERROR_INVALID_PLUGPLAY_DEVICE_PATH 620L

//
// MessageId: ERROR_QUOTA_LIST_INCONSISTENT
//
// MessageText:
//
// The specified quota list is internally inconsistent with its descriptor.
//
#define ERROR_QUOTA_LIST_INCONSISTENT    621L

//
// MessageId: ERROR_EVALUATION_EXPIRATION
//
// MessageText:
//
// {Windows Evaluation Notification}
// The evaluation period for this installation of Windows has expired. This system will shutdown in 1 hour. To restore access to this installation of Windows, please upgrade this installation using a licensed distribution of this product.
//
#define ERROR_EVALUATION_EXPIRATION      622L

//
// MessageId: ERROR_ILLEGAL_DLL_RELOCATION
//
// MessageText:
//
// {Illegal System DLL Relocation}
// The system DLL %hs was relocated in memory. The application will not run properly.
// The relocation occurred because the DLL %hs occupied an address range reserved for Windows system DLLs. The vendor supplying the DLL should be contacted for a new DLL.
//
#define ERROR_ILLEGAL_DLL_RELOCATION     623L

//
// MessageId: ERROR_DLL_INIT_FAILED_LOGOFF
//
// MessageText:
//
// {DLL Initialization Failed}
// The application failed to initialize because the window station is shutting down.
//
#define ERROR_DLL_INIT_FAILED_LOGOFF     624L

//
// MessageId: ERROR_VALIDATE_CONTINUE
//
// MessageText:
//
// The validation process needs to continue on to the next step.
//
#define ERROR_VALIDATE_CONTINUE          625L

//
// MessageId: ERROR_NO_MORE_MATCHES
//
// MessageText:
//
// There are no more matches for the current index enumeration.
//
#define ERROR_NO_MORE_MATCHES            626L

//
// MessageId: ERROR_RANGE_LIST_CONFLICT
//
// MessageText:
//
// The range could not be added to the range list because of a conflict.
//
#define ERROR_RANGE_LIST_CONFLICT        627L

//
// MessageId: ERROR_SERVER_SID_MISMATCH
//
// MessageText:
//
// The server process is running under a SID different than that required by client.
//
#define ERROR_SERVER_SID_MISMATCH        628L

//
// MessageId: ERROR_CANT_ENABLE_DENY_ONLY
//
// MessageText:
//
// A group marked use for deny only  cannot be enabled.
//
#define ERROR_CANT_ENABLE_DENY_ONLY      629L

//
// MessageId: ERROR_FLOAT_MULTIPLE_FAULTS
//
// MessageText:
//
// {EXCEPTION}
// Multiple floating point faults.
//
#define ERROR_FLOAT_MULTIPLE_FAULTS      630L    // winnt

//
// MessageId: ERROR_FLOAT_MULTIPLE_TRAPS
//
// MessageText:
//
// {EXCEPTION}
// Multiple floating point traps.
//
#define ERROR_FLOAT_MULTIPLE_TRAPS       631L    // winnt

//
// MessageId: ERROR_NOINTERFACE
//
// MessageText:
//
// The requested interface is not supported.
//
#define ERROR_NOINTERFACE                632L

//
// MessageId: ERROR_DRIVER_FAILED_SLEEP
//
// MessageText:
//
// {System Standby Failed}
// The driver %hs does not support standby mode. Updating this driver may allow the system to go to standby mode.
//
#define ERROR_DRIVER_FAILED_SLEEP        633L

//
// MessageId: ERROR_CORRUPT_SYSTEM_FILE
//
// MessageText:
//
// The system file %1 has become corrupt and has been replaced.
//
#define ERROR_CORRUPT_SYSTEM_FILE        634L

//
// MessageId: ERROR_COMMITMENT_MINIMUM
//
// MessageText:
//
// {Virtual Memory Minimum Too Low}
// Your system is low on virtual memory. Windows is increasing the size of your virtual memory paging file.
// During this process, memory requests for some applications may be denied. For more information, see Help.
//
#define ERROR_COMMITMENT_MINIMUM         635L

//
// MessageId: ERROR_PNP_RESTART_ENUMERATION
//
// MessageText:
//
// A device was removed so enumeration must be restarted.
//
#define ERROR_PNP_RESTART_ENUMERATION    636L

//
// MessageId: ERROR_SYSTEM_IMAGE_BAD_SIGNATURE
//
// MessageText:
//
// {Fatal System Error}
// The system image %s is not properly signed.
// The file has been replaced with the signed file.
// The system has been shut down.
//
#define ERROR_SYSTEM_IMAGE_BAD_SIGNATURE 637L

//
// MessageId: ERROR_PNP_REBOOT_REQUIRED
//
// MessageText:
//
// Device will not start without a reboot.
//
#define ERROR_PNP_REBOOT_REQUIRED        638L

//
// MessageId: ERROR_INSUFFICIENT_POWER
//
// MessageText:
//
// There is not enough power to complete the requested operation.
//
#define ERROR_INSUFFICIENT_POWER         639L

//
// MessageId: ERROR_MULTIPLE_FAULT_VIOLATION
//
// MessageText:
//
//  ERROR_MULTIPLE_FAULT_VIOLATION
//
#define ERROR_MULTIPLE_FAULT_VIOLATION   640L

//
// MessageId: ERROR_SYSTEM_SHUTDOWN
//
// MessageText:
//
// The system is in the process of shutting down.
//
#define ERROR_SYSTEM_SHUTDOWN            641L

//
// MessageId: ERROR_PORT_NOT_SET
//
// MessageText:
//
// An attempt to remove a processes DebugPort was made, but a port was not already associated with the process.
//
#define ERROR_PORT_NOT_SET               642L

//
// MessageId: ERROR_DS_VERSION_CHECK_FAILURE
//
// MessageText:
//
// This version of Windows is not compatible with the behavior version of directory forest, domain or domain controller.
//
#define ERROR_DS_VERSION_CHECK_FAILURE   643L

//
// MessageId: ERROR_RANGE_NOT_FOUND
//
// MessageText:
//
// The specified range could not be found in the range list.
//
#define ERROR_RANGE_NOT_FOUND            644L

//
// MessageId: ERROR_NOT_SAFE_MODE_DRIVER
//
// MessageText:
//
// The driver was not loaded because the system is booting into safe mode.
//
#define ERROR_NOT_SAFE_MODE_DRIVER       646L

//
// MessageId: ERROR_FAILED_DRIVER_ENTRY
//
// MessageText:
//
// The driver was not loaded because it failed it's initialization call.
//
#define ERROR_FAILED_DRIVER_ENTRY        647L

//
// MessageId: ERROR_DEVICE_ENUMERATION_ERROR
//
// MessageText:
//
// The "%hs" encountered an error while applying power or reading the device configuration.
// This may be caused by a failure of your hardware or by a poor connection.
//
#define ERROR_DEVICE_ENUMERATION_ERROR   648L

//
// MessageId: ERROR_MOUNT_POINT_NOT_RESOLVED
//
// MessageText:
//
// The create operation failed because the name contained at least one mount point which resolves to a volume to which the specified device object is not attached.
//
#define ERROR_MOUNT_POINT_NOT_RESOLVED   649L

//
// MessageId: ERROR_INVALID_DEVICE_OBJECT_PARAMETER
//
// MessageText:
//
// The device object parameter is either not a valid device object or is not attached to the volume specified by the file name.
//
#define ERROR_INVALID_DEVICE_OBJECT_PARAMETER 650L

//
// MessageId: ERROR_MCA_OCCURED
//
// MessageText:
//
// A Machine Check Error has occurred. Please check the system eventlog for additional information.
//
#define ERROR_MCA_OCCURED                651L

//
// MessageId: ERROR_DRIVER_DATABASE_ERROR
//
// MessageText:
//
// There was error [%2] processing the driver database.
//
#define ERROR_DRIVER_DATABASE_ERROR      652L

//
// MessageId: ERROR_SYSTEM_HIVE_TOO_LARGE
//
// MessageText:
//
// System hive size has exceeded its limit.
//
#define ERROR_SYSTEM_HIVE_TOO_LARGE      653L

//
// MessageId: ERROR_DRIVER_FAILED_PRIOR_UNLOAD
//
// MessageText:
//
// The driver could not be loaded because a previous version of the driver is still in memory.
//
#define ERROR_DRIVER_FAILED_PRIOR_UNLOAD 654L

//
// MessageId: ERROR_VOLSNAP_PREPARE_HIBERNATE
//
// MessageText:
//
// {Volume Shadow Copy Service}
// Please wait while the Volume Shadow Copy Service prepares volume %hs for hibernation.
//
#define ERROR_VOLSNAP_PREPARE_HIBERNATE  655L

//
// MessageId: ERROR_HIBERNATION_FAILURE
//
// MessageText:
//
// The system has failed to hibernate (The error code is %hs). Hibernation will be disabled until the system is restarted.
//
#define ERROR_HIBERNATION_FAILURE        656L

//
// MessageId: ERROR_FILE_SYSTEM_LIMITATION
//
// MessageText:
//
// The requested operation could not be completed due to a file system limitation
//
#define ERROR_FILE_SYSTEM_LIMITATION     665L

//
// MessageId: ERROR_ASSERTION_FAILURE
//
// MessageText:
//
// An assertion failure has occurred.
//
#define ERROR_ASSERTION_FAILURE          668L

//
// MessageId: ERROR_ACPI_ERROR
//
// MessageText:
//
// An error occurred in the ACPI subsystem.
//
#define ERROR_ACPI_ERROR                 669L

//
// MessageId: ERROR_WOW_ASSERTION
//
// MessageText:
//
// WOW Assertion Error.
//
#define ERROR_WOW_ASSERTION              670L

//
// MessageId: ERROR_PNP_BAD_MPS_TABLE
//
// MessageText:
//
// A device is missing in the system BIOS MPS table. This device will not be used.
// Please contact your system vendor for system BIOS update.
//
#define ERROR_PNP_BAD_MPS_TABLE          671L

//
// MessageId: ERROR_PNP_TRANSLATION_FAILED
//
// MessageText:
//
// A translator failed to translate resources.
//
#define ERROR_PNP_TRANSLATION_FAILED     672L

//
// MessageId: ERROR_PNP_IRQ_TRANSLATION_FAILED
//
// MessageText:
//
// A IRQ translator failed to translate resources.
//
#define ERROR_PNP_IRQ_TRANSLATION_FAILED 673L

//
// MessageId: ERROR_PNP_INVALID_ID
//
// MessageText:
//
// Driver %2 returned invalid ID for a child device (%3).
//
#define ERROR_PNP_INVALID_ID             674L

//
// MessageId: ERROR_WAKE_SYSTEM_DEBUGGER
//
// MessageText:
//
// {Kernel Debugger Awakened}
// the system debugger was awakened by an interrupt.
//
#define ERROR_WAKE_SYSTEM_DEBUGGER       675L

//
// MessageId: ERROR_HANDLES_CLOSED
//
// MessageText:
//
// {Handles Closed}
// Handles to objects have been automatically closed as a result of the requested operation.
//
#define ERROR_HANDLES_CLOSED             676L

//
// MessageId: ERROR_EXTRANEOUS_INFORMATION
//
// MessageText:
//
// {Too Much Information}
// The specified access control list (ACL) contained more information than was expected.
//
#define ERROR_EXTRANEOUS_INFORMATION     677L

//
// MessageId: ERROR_RXACT_COMMIT_NECESSARY
//
// MessageText:
//
// This warning level status indicates that the transaction state already exists for the registry sub-tree, but that a transaction commit was previously aborted.
// The commit has NOT been completed, but has not been rolled back either (so it may still be committed if desired).
//
#define ERROR_RXACT_COMMIT_NECESSARY     678L

//
// MessageId: ERROR_MEDIA_CHECK
//
// MessageText:
//
// {Media Changed}
// The media may have changed.
//
#define ERROR_MEDIA_CHECK                679L

//
// MessageId: ERROR_GUID_SUBSTITUTION_MADE
//
// MessageText:
//
// {GUID Substitution}
// During the translation of a global identifier (GUID) to a Windows security ID (SID), no administratively-defined GUID prefix was found.
// A substitute prefix was used, which will not compromise system security.
// However, this may provide a more restrictive access than intended.
//
#define ERROR_GUID_SUBSTITUTION_MADE     680L

//
// MessageId: ERROR_STOPPED_ON_SYMLINK
//
// MessageText:
//
// The create operation stopped after reaching a symbolic link
//
#define ERROR_STOPPED_ON_SYMLINK         681L

//
// MessageId: ERROR_LONGJUMP
//
// MessageText:
//
// A long jump has been executed.
//
#define ERROR_LONGJUMP                   682L

//
// MessageId: ERROR_PLUGPLAY_QUERY_VETOED
//
// MessageText:
//
// The Plug and Play query operation was not successful.
//
#define ERROR_PLUGPLAY_QUERY_VETOED      683L

//
// MessageId: ERROR_UNWIND_CONSOLIDATE
//
// MessageText:
//
// A frame consolidation has been executed.
//
#define ERROR_UNWIND_CONSOLIDATE         684L

//
// MessageId: ERROR_REGISTRY_HIVE_RECOVERED
//
// MessageText:
//
// {Registry Hive Recovered}
// Registry hive (file):
// %hs
// was corrupted and it has been recovered. Some data might have been lost.
//
#define ERROR_REGISTRY_HIVE_RECOVERED    685L

//
// MessageId: ERROR_DLL_MIGHT_BE_INSECURE
//
// MessageText:
//
// The application is attempting to run executable code from the module %hs. This may be insecure. An alternative, %hs, is available. Should the application use the secure module %hs?
//
#define ERROR_DLL_MIGHT_BE_INSECURE      686L

//
// MessageId: ERROR_DLL_MIGHT_BE_INCOMPATIBLE
//
// MessageText:
//
// The application is loading executable code from the module %hs. This is secure, but may be incompatible with previous releases of the operating system. An alternative, %hs, is available. Should the application use the secure module %hs?
//
#define ERROR_DLL_MIGHT_BE_INCOMPATIBLE  687L

//
// MessageId: ERROR_DBG_EXCEPTION_NOT_HANDLED
//
// MessageText:
//
// Debugger did not handle the exception.
//
#define ERROR_DBG_EXCEPTION_NOT_HANDLED  688L    // winnt

//
// MessageId: ERROR_DBG_REPLY_LATER
//
// MessageText:
//
// Debugger will reply later.
//
#define ERROR_DBG_REPLY_LATER            689L

//
// MessageId: ERROR_DBG_UNABLE_TO_PROVIDE_HANDLE
//
// MessageText:
//
// Debugger cannot provide handle.
//
#define ERROR_DBG_UNABLE_TO_PROVIDE_HANDLE 690L

//
// MessageId: ERROR_DBG_TERMINATE_THREAD
//
// MessageText:
//
// Debugger terminated thread.
//
#define ERROR_DBG_TERMINATE_THREAD       691L    // winnt

//
// MessageId: ERROR_DBG_TERMINATE_PROCESS
//
// MessageText:
//
// Debugger terminated process.
//
#define ERROR_DBG_TERMINATE_PROCESS      692L    // winnt

//
// MessageId: ERROR_DBG_CONTROL_C
//
// MessageText:
//
// Debugger got control C.
//
#define ERROR_DBG_CONTROL_C              693L    // winnt

//
// MessageId: ERROR_DBG_PRINTEXCEPTION_C
//
// MessageText:
//
// Debugger printed exception on control C.
//
#define ERROR_DBG_PRINTEXCEPTION_C       694L

//
// MessageId: ERROR_DBG_RIPEXCEPTION
//
// MessageText:
//
// Debugger received RIP exception.
//
#define ERROR_DBG_RIPEXCEPTION           695L

//
// MessageId: ERROR_DBG_CONTROL_BREAK
//
// MessageText:
//
// Debugger received control break.
//
#define ERROR_DBG_CONTROL_BREAK          696L    // winnt

//
// MessageId: ERROR_DBG_COMMAND_EXCEPTION
//
// MessageText:
//
// Debugger command communication exception.
//
#define ERROR_DBG_COMMAND_EXCEPTION      697L    // winnt

//
// MessageId: ERROR_OBJECT_NAME_EXISTS
//
// MessageText:
//
// {Object Exists}
// An attempt was made to create an object and the object name already existed.
//
#define ERROR_OBJECT_NAME_EXISTS         698L

//
// MessageId: ERROR_THREAD_WAS_SUSPENDED
//
// MessageText:
//
// {Thread Suspended}
// A thread termination occurred while the thread was suspended. The thread was resumed, and termination proceeded.
//
#define ERROR_THREAD_WAS_SUSPENDED       699L

//
// MessageId: ERROR_IMAGE_NOT_AT_BASE
//
// MessageText:
//
// {Image Relocated}
// An image file could not be mapped at the address specified in the image file. Local fixups must be performed on this image.
//
#define ERROR_IMAGE_NOT_AT_BASE          700L

//
// MessageId: ERROR_RXACT_STATE_CREATED
//
// MessageText:
//
// This informational level status indicates that a specified registry sub-tree transaction state did not yet exist and had to be created.
//
#define ERROR_RXACT_STATE_CREATED        701L

//
// MessageId: ERROR_SEGMENT_NOTIFICATION
//
// MessageText:
//
// {Segment Load}
// A virtual DOS machine (VDM) is loading, unloading, or moving an MS-DOS or Win16 program segment image.
// An exception is raised so a debugger can load, unload or track symbols and breakpoints within these 16-bit segments.
//
#define ERROR_SEGMENT_NOTIFICATION       702L    // winnt

//
// MessageId: ERROR_BAD_CURRENT_DIRECTORY
//
// MessageText:
//
// {Invalid Current Directory}
// The process cannot switch to the startup current directory %hs.
// Select OK to set current directory to %hs, or select CANCEL to exit.
//
#define ERROR_BAD_CURRENT_DIRECTORY      703L

//
// MessageId: ERROR_FT_READ_RECOVERY_FROM_BACKUP
//
// MessageText:
//
// {Redundant Read}
// To satisfy a read request, the NT fault-tolerant file system successfully read the requested data from a redundant copy.
// This was done because the file system encountered a failure on a member of the fault-tolerant volume, but was unable to reassign the failing area of the device.
//
#define ERROR_FT_READ_RECOVERY_FROM_BACKUP 704L

//
// MessageId: ERROR_FT_WRITE_RECOVERY
//
// MessageText:
//
// {Redundant Write}
// To satisfy a write request, the NT fault-tolerant file system successfully wrote a redundant copy of the information.
// This was done because the file system encountered a failure on a member of the fault-tolerant volume, but was not able to reassign the failing area of the device.
//
#define ERROR_FT_WRITE_RECOVERY          705L

//
// MessageId: ERROR_IMAGE_MACHINE_TYPE_MISMATCH
//
// MessageText:
//
// {Machine Type Mismatch}
// The image file %hs is valid, but is for a machine type other than the current machine. Select OK to continue, or CANCEL to fail the DLL load.
//
#define ERROR_IMAGE_MACHINE_TYPE_MISMATCH 706L

//
// MessageId: ERROR_RECEIVE_PARTIAL
//
// MessageText:
//
// {Partial Data Received}
// The network transport returned partial data to its client. The remaining data will be sent later.
//
#define ERROR_RECEIVE_PARTIAL            707L

//
// MessageId: ERROR_RECEIVE_EXPEDITED
//
// MessageText:
//
// {Expedited Data Received}
// The network transport returned data to its client that was marked as expedited by the remote system.
//
#define ERROR_RECEIVE_EXPEDITED          708L

//
// MessageId: ERROR_RECEIVE_PARTIAL_EXPEDITED
//
// MessageText:
//
// {Partial Expedited Data Received}
// The network transport returned partial data to its client and this data was marked as expedited by the remote system. The remaining data will be sent later.
//
#define ERROR_RECEIVE_PARTIAL_EXPEDITED  709L

//
// MessageId: ERROR_EVENT_DONE
//
// MessageText:
//
// {TDI Event Done}
// The TDI indication has completed successfully.
//
#define ERROR_EVENT_DONE                 710L

//
// MessageId: ERROR_EVENT_PENDING
//
// MessageText:
//
// {TDI Event Pending}
// The TDI indication has entered the pending state.
//
#define ERROR_EVENT_PENDING              711L

//
// MessageId: ERROR_CHECKING_FILE_SYSTEM
//
// MessageText:
//
// Checking file system on %wZ
//
#define ERROR_CHECKING_FILE_SYSTEM       712L

//
// MessageId: ERROR_FATAL_APP_EXIT
//
// MessageText:
//
// {Fatal Application Exit}
// %hs
//
#define ERROR_FATAL_APP_EXIT             713L

//
// MessageId: ERROR_PREDEFINED_HANDLE
//
// MessageText:
//
// The specified registry key is referenced by a predefined handle.
//
#define ERROR_PREDEFINED_HANDLE          714L

//
// MessageId: ERROR_WAS_UNLOCKED
//
// MessageText:
//
// {Page Unlocked}
// The page protection of a locked page was changed to 'No Access' and the page was unlocked from memory and from the process.
//
#define ERROR_WAS_UNLOCKED               715L

//
// MessageId: ERROR_SERVICE_NOTIFICATION
//
// MessageText:
//
// %hs
//
#define ERROR_SERVICE_NOTIFICATION       716L

//
// MessageId: ERROR_WAS_LOCKED
//
// MessageText:
//
// {Page Locked}
// One of the pages to lock was already locked.
//
#define ERROR_WAS_LOCKED                 717L

//
// MessageId: ERROR_LOG_HARD_ERROR
//
// MessageText:
//
// Application popup: %1 : %2
//
#define ERROR_LOG_HARD_ERROR             718L

//
// MessageId: ERROR_ALREADY_WIN32
//
// MessageText:
//
//  ERROR_ALREADY_WIN32
//
#define ERROR_ALREADY_WIN32              719L

//
// MessageId: ERROR_IMAGE_MACHINE_TYPE_MISMATCH_EXE
//
// MessageText:
//
// {Machine Type Mismatch}
// The image file %hs is valid, but is for a machine type other than the current machine.
//
#define ERROR_IMAGE_MACHINE_TYPE_MISMATCH_EXE 720L

//
// MessageId: ERROR_NO_YIELD_PERFORMED
//
// MessageText:
//
// A yield execution was performed and no thread was available to run.
//
#define ERROR_NO_YIELD_PERFORMED         721L

//
// MessageId: ERROR_TIMER_RESUME_IGNORED
//
// MessageText:
//
// The resumable flag to a timer API was ignored.
//
#define ERROR_TIMER_RESUME_IGNORED       722L

//
// MessageId: ERROR_ARBITRATION_UNHANDLED
//
// MessageText:
//
// The arbiter has deferred arbitration of these resources to its parent
//
#define ERROR_ARBITRATION_UNHANDLED      723L

//
// MessageId: ERROR_CARDBUS_NOT_SUPPORTED
//
// MessageText:
//
// The inserted CardBus device cannot be started because of a configuration error on "%hs".
//
#define ERROR_CARDBUS_NOT_SUPPORTED      724L

//
// MessageId: ERROR_MP_PROCESSOR_MISMATCH
//
// MessageText:
//
// The CPUs in this multiprocessor system are not all the same revision level. To use all processors the operating system restricts itself to the features of the least capable processor in the system. Should problems occur with this system, contact the CPU manufacturer to see if this mix of processors is supported.
//
#define ERROR_MP_PROCESSOR_MISMATCH      725L

//
// MessageId: ERROR_HIBERNATED
//
// MessageText:
//
// The system was put into hibernation.
//
#define ERROR_HIBERNATED                 726L    

//
// MessageId: ERROR_RESUME_HIBERNATION
//
// MessageText:
//
// The system was resumed from hibernation.
//
#define ERROR_RESUME_HIBERNATION         727L    

//
// MessageId: ERROR_FIRMWARE_UPDATED
//
// MessageText:
//
// Windows has detected that the system firmware (BIOS) was updated [previous firmware date = %2, current firmware date %3].
//
#define ERROR_FIRMWARE_UPDATED           728L

//
// MessageId: ERROR_DRIVERS_LEAKING_LOCKED_PAGES
//
// MessageText:
//
// A device driver is leaking locked I/O pages causing system degradation. The system has automatically enabled tracking code in order to try and catch the culprit.
//
#define ERROR_DRIVERS_LEAKING_LOCKED_PAGES 729L

//
// MessageId: ERROR_WAKE_SYSTEM
//
// MessageText:
//
// The system has awoken
//
#define ERROR_WAKE_SYSTEM                730L

//
// MessageId: ERROR_WAIT_1
//
// MessageText:
//
//  ERROR_WAIT_1
//
#define ERROR_WAIT_1                     731L

//
// MessageId: ERROR_WAIT_2
//
// MessageText:
//
//  ERROR_WAIT_2
//
#define ERROR_WAIT_2                     732L

//
// MessageId: ERROR_WAIT_3
//
// MessageText:
//
//  ERROR_WAIT_3
//
#define ERROR_WAIT_3                     733L

//
// MessageId: ERROR_WAIT_63
//
// MessageText:
//
//  ERROR_WAIT_63
//
#define ERROR_WAIT_63                    734L

//
// MessageId: ERROR_ABANDONED_WAIT_0
//
// MessageText:
//
//  ERROR_ABANDONED_WAIT_0
//
#define ERROR_ABANDONED_WAIT_0           735L    // winnt

//
// MessageId: ERROR_ABANDONED_WAIT_63
//
// MessageText:
//
//  ERROR_ABANDONED_WAIT_63
//
#define ERROR_ABANDONED_WAIT_63          736L

//
// MessageId: ERROR_USER_APC
//
// MessageText:
//
//  ERROR_USER_APC
//
#define ERROR_USER_APC                   737L    // winnt

//
// MessageId: ERROR_KERNEL_APC
//
// MessageText:
//
//  ERROR_KERNEL_APC
//
#define ERROR_KERNEL_APC                 738L

//
// MessageId: ERROR_ALERTED
//
// MessageText:
//
//  ERROR_ALERTED
//
#define ERROR_ALERTED                    739L

//
// MessageId: ERROR_ELEVATION_REQUIRED
//
// MessageText:
//
// The requested operation requires elevation.
//
#define ERROR_ELEVATION_REQUIRED         740L

//
// MessageId: ERROR_REPARSE
//
// MessageText:
//
// A reparse should be performed by the Object Manager since the name of the file resulted in a symbolic link.
//
#define ERROR_REPARSE                    741L

//
// MessageId: ERROR_OPLOCK_BREAK_IN_PROGRESS
//
// MessageText:
//
// An open/create operation completed while an oplock break is underway.
//
#define ERROR_OPLOCK_BREAK_IN_PROGRESS   742L

//
// MessageId: ERROR_VOLUME_MOUNTED
//
// MessageText:
//
// A new volume has been mounted by a file system.
//
#define ERROR_VOLUME_MOUNTED             743L

//
// MessageId: ERROR_RXACT_COMMITTED
//
// MessageText:
//
// This success level status indicates that the transaction state already exists for the registry sub-tree, but that a transaction commit was previously aborted.
// The commit has now been completed.
//
#define ERROR_RXACT_COMMITTED            744L

//
// MessageId: ERROR_NOTIFY_CLEANUP
//
// MessageText:
//
// This indicates that a notify change request has been completed due to closing the handle which made the notify change request.
//
#define ERROR_NOTIFY_CLEANUP             745L

//
// MessageId: ERROR_PRIMARY_TRANSPORT_CONNECT_FAILED
//
// MessageText:
//
// {Connect Failure on Primary Transport}
// An attempt was made to connect to the remote server %hs on the primary transport, but the connection failed.
// The computer WAS able to connect on a secondary transport.
//
#define ERROR_PRIMARY_TRANSPORT_CONNECT_FAILED 746L

//
// MessageId: ERROR_PAGE_FAULT_TRANSITION
//
// MessageText:
//
// Page fault was a transition fault.
//
#define ERROR_PAGE_FAULT_TRANSITION      747L

//
// MessageId: ERROR_PAGE_FAULT_DEMAND_ZERO
//
// MessageText:
//
// Page fault was a demand zero fault.
//
#define ERROR_PAGE_FAULT_DEMAND_ZERO     748L

//
// MessageId: ERROR_PAGE_FAULT_COPY_ON_WRITE
//
// MessageText:
//
// Page fault was a demand zero fault.
//
#define ERROR_PAGE_FAULT_COPY_ON_WRITE   749L

//
// MessageId: ERROR_PAGE_FAULT_GUARD_PAGE
//
// MessageText:
//
// Page fault was a demand zero fault.
//
#define ERROR_PAGE_FAULT_GUARD_PAGE      750L

//
// MessageId: ERROR_PAGE_FAULT_PAGING_FILE
//
// MessageText:
//
// Page fault was satisfied by reading from a secondary storage device.
//
#define ERROR_PAGE_FAULT_PAGING_FILE     751L

//
// MessageId: ERROR_CACHE_PAGE_LOCKED
//
// MessageText:
//
// Cached page was locked during operation.
//
#define ERROR_CACHE_PAGE_LOCKED          752L

//
// MessageId: ERROR_CRASH_DUMP
//
// MessageText:
//
// Crash dump exists in paging file.
//
#define ERROR_CRASH_DUMP                 753L

//
// MessageId: ERROR_BUFFER_ALL_ZEROS
//
// MessageText:
//
// Specified buffer contains all zeros.
//
#define ERROR_BUFFER_ALL_ZEROS           754L

//
// MessageId: ERROR_REPARSE_OBJECT
//
// MessageText:
//
// A reparse should be performed by the Object Manager since the name of the file resulted in a symbolic link.
//
#define ERROR_REPARSE_OBJECT             755L

//
// MessageId: ERROR_RESOURCE_REQUIREMENTS_CHANGED
//
// MessageText:
//
// The device has succeeded a query-stop and its resource requirements have changed.
//
#define ERROR_RESOURCE_REQUIREMENTS_CHANGED 756L

//
// MessageId: ERROR_TRANSLATION_COMPLETE
//
// MessageText:
//
// The translator has translated these resources into the global space and no further translations should be performed.
//
#define ERROR_TRANSLATION_COMPLETE       757L

//
// MessageId: ERROR_NOTHING_TO_TERMINATE
//
// MessageText:
//
// A process being terminated has no threads to terminate.
//
#define ERROR_NOTHING_TO_TERMINATE       758L

//
// MessageId: ERROR_PROCESS_NOT_IN_JOB
//
// MessageText:
//
// The specified process is not part of a job.
//
#define ERROR_PROCESS_NOT_IN_JOB         759L

//
// MessageId: ERROR_PROCESS_IN_JOB
//
// MessageText:
//
// The specified process is part of a job.
//
#define ERROR_PROCESS_IN_JOB             760L

//
// MessageId: ERROR_VOLSNAP_HIBERNATE_READY
//
// MessageText:
//
// {Volume Shadow Copy Service}
// The system is now ready for hibernation.
//
#define ERROR_VOLSNAP_HIBERNATE_READY    761L

//
// MessageId: ERROR_FSFILTER_OP_COMPLETED_SUCCESSFULLY
//
// MessageText:
//
// A file system or file system filter driver has successfully completed an FsFilter operation.
//
#define ERROR_FSFILTER_OP_COMPLETED_SUCCESSFULLY 762L

//
// MessageId: ERROR_INTERRUPT_VECTOR_ALREADY_CONNECTED
//
// MessageText:
//
// The specified interrupt vector was already connected.
//
#define ERROR_INTERRUPT_VECTOR_ALREADY_CONNECTED 763L

//
// MessageId: ERROR_INTERRUPT_STILL_CONNECTED
//
// MessageText:
//
// The specified interrupt vector is still connected.
//
#define ERROR_INTERRUPT_STILL_CONNECTED  764L

//
// MessageId: ERROR_WAIT_FOR_OPLOCK
//
// MessageText:
//
// An operation is blocked waiting for an oplock.
//
#define ERROR_WAIT_FOR_OPLOCK            765L

//
// MessageId: ERROR_DBG_EXCEPTION_HANDLED
//
// MessageText:
//
// Debugger handled exception
//
#define ERROR_DBG_EXCEPTION_HANDLED      766L    // winnt

//
// MessageId: ERROR_DBG_CONTINUE
//
// MessageText:
//
// Debugger continued
//
#define ERROR_DBG_CONTINUE               767L    // winnt

//
// MessageId: ERROR_CALLBACK_POP_STACK
//
// MessageText:
//
// An exception occurred in a user mode callback and the kernel callback frame should be removed.
//
#define ERROR_CALLBACK_POP_STACK         768L

//
// MessageId: ERROR_COMPRESSION_DISABLED
//
// MessageText:
//
// Compression is disabled for this volume.
//
#define ERROR_COMPRESSION_DISABLED       769L

//
// MessageId: ERROR_CANTFETCHBACKWARDS
//
// MessageText:
//
// The data provider cannot fetch backwards through a result set.
//
#define ERROR_CANTFETCHBACKWARDS         770L

//
// MessageId: ERROR_CANTSCROLLBACKWARDS
//
// MessageText:
//
// The data provider cannot scroll backwards through a result set.
//
#define ERROR_CANTSCROLLBACKWARDS        771L

//
// MessageId: ERROR_ROWSNOTRELEASED
//
// MessageText:
//
// The data provider requires that previously fetched data is released before asking for more data.
//
#define ERROR_ROWSNOTRELEASED            772L

//
// MessageId: ERROR_BAD_ACCESSOR_FLAGS
//
// MessageText:
//
// The data provider was not able to intrepret the flags set for a column binding in an accessor.
//
#define ERROR_BAD_ACCESSOR_FLAGS         773L

//
// MessageId: ERROR_ERRORS_ENCOUNTERED
//
// MessageText:
//
// One or more errors occurred while processing the request.
//
#define ERROR_ERRORS_ENCOUNTERED         774L

//
// MessageId: ERROR_NOT_CAPABLE
//
// MessageText:
//
// The implementation is not capable of performing the request.
//
#define ERROR_NOT_CAPABLE                775L

//
// MessageId: ERROR_REQUEST_OUT_OF_SEQUENCE
//
// MessageText:
//
// The client of a component requested an operation which is not valid given the state of the component instance.
//
#define ERROR_REQUEST_OUT_OF_SEQUENCE    776L

//
// MessageId: ERROR_VERSION_PARSE_ERROR
//
// MessageText:
//
// A version number could not be parsed.
//
#define ERROR_VERSION_PARSE_ERROR        777L

//
// MessageId: ERROR_BADSTARTPOSITION
//
// MessageText:
//
// The iterator's start position is invalid.
//
#define ERROR_BADSTARTPOSITION           778L

//
// MessageId: ERROR_MEMORY_HARDWARE
//
// MessageText:
//
// The hardware has reported an uncorrectable memory error.
//
#define ERROR_MEMORY_HARDWARE            779L

//
// MessageId: ERROR_DISK_REPAIR_DISABLED
//
// MessageText:
//
// The attempted operation required self healing to be enabled.
//
#define ERROR_DISK_REPAIR_DISABLED       780L

//
// MessageId: ERROR_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE
//
// MessageText:
//
// The Desktop heap encountered an error while allocating session memory.
// There is more information in the system event log.
//
#define ERROR_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE 781L

//
// MessageId: ERROR_SYSTEM_POWERSTATE_TRANSITION
//
// MessageText:
//
// The system powerstate is transitioning from %2 to %3.
//
#define ERROR_SYSTEM_POWERSTATE_TRANSITION 782L

//
// MessageId: ERROR_SYSTEM_POWERSTATE_COMPLEX_TRANSITION
//
// MessageText:
//
// The system powerstate is transitioning from %2 to %3 but could enter %4.
//
#define ERROR_SYSTEM_POWERSTATE_COMPLEX_TRANSITION 783L

//
// MessageId: ERROR_MCA_EXCEPTION
//
// MessageText:
//
// A thread is getting dispatched with MCA EXCEPTION because of MCA.
//
#define ERROR_MCA_EXCEPTION              784L

//
// MessageId: ERROR_ACCESS_AUDIT_BY_POLICY
//
// MessageText:
//
// Access to %1 is monitored by policy rule %2.
//
#define ERROR_ACCESS_AUDIT_BY_POLICY     785L

//
// MessageId: ERROR_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY
//
// MessageText:
//
// Access to %1 has been restricted by your Administrator by policy rule %2.
//
#define ERROR_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY 786L

//
// MessageId: ERROR_ABANDON_HIBERFILE
//
// MessageText:
//
// A valid hibernation file has been invalidated and should be abandoned.
//
#define ERROR_ABANDON_HIBERFILE          787L

//
// MessageId: ERROR_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED
//
// MessageText:
//
// {Delayed Write Failed}
// Windows was unable to save all the data for the file %hs; the data has been lost.
// This error may be caused by network connectivity issues. Please try to save this file elsewhere.
//
#define ERROR_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED 788L

//
// MessageId: ERROR_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR
//
// MessageText:
//
// {Delayed Write Failed}
// Windows was unable to save all the data for the file %hs; the data has been lost.
// This error was returned by the server on which the file exists. Please try to save this file elsewhere.
//
#define ERROR_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR 789L

//
// MessageId: ERROR_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR
//
// MessageText:
//
// {Delayed Write Failed}
// Windows was unable to save all the data for the file %hs; the data has been lost.
// This error may be caused if the device has been removed or the media is write-protected.
//
#define ERROR_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR 790L

//
// MessageId: ERROR_BAD_MCFG_TABLE
//
// MessageText:
//
// The resources required for this device conflict with the MCFG table.
//
#define ERROR_BAD_MCFG_TABLE             791L

//
// MessageId: ERROR_EA_ACCESS_DENIED
//
// MessageText:
//
// Access to the extended attribute was denied.
//
#define ERROR_EA_ACCESS_DENIED           994L

//
// MessageId: ERROR_OPERATION_ABORTED
//
// MessageText:
//
// The I/O operation has been aborted because of either a thread exit or an application request.
//
#define ERROR_OPERATION_ABORTED          995L

//
// MessageId: ERROR_IO_INCOMPLETE
//
// MessageText:
//
// Overlapped I/O event is not in a signaled state.
//
#define ERROR_IO_INCOMPLETE              996L

//
// MessageId: ERROR_IO_PENDING
//
// MessageText:
//
// Overlapped I/O operation is in progress.
//
#define ERROR_IO_PENDING                 997L    // dderror

//
// MessageId: ERROR_NOACCESS
//
// MessageText:
//
// Invalid access to memory location.
//
#define ERROR_NOACCESS                   998L

//
// MessageId: ERROR_SWAPERROR
//
// MessageText:
//
// Error performing inpage operation.
//
#define ERROR_SWAPERROR                  999L

//
// MessageId: ERROR_STACK_OVERFLOW
//
// MessageText:
//
// Recursion too deep; the stack overflowed.
//
#define ERROR_STACK_OVERFLOW             1001L

//
// MessageId: ERROR_INVALID_MESSAGE
//
// MessageText:
//
// The window cannot act on the sent message.
//
#define ERROR_INVALID_MESSAGE            1002L

//
// MessageId: ERROR_CAN_NOT_COMPLETE
//
// MessageText:
//
// Cannot complete this function.
//
#define ERROR_CAN_NOT_COMPLETE           1003L

//
// MessageId: ERROR_INVALID_FLAGS
//
// MessageText:
//
// Invalid flags.
//
#define ERROR_INVALID_FLAGS              1004L

//
// MessageId: ERROR_UNRECOGNIZED_VOLUME
//
// MessageText:
//
// The volume does not contain a recognized file system.
// Please make sure that all required file system drivers are loaded and that the volume is not corrupted.
//
#define ERROR_UNRECOGNIZED_VOLUME        1005L

//
// MessageId: ERROR_FILE_INVALID
//
// MessageText:
//
// The volume for a file has been externally altered so that the opened file is no longer valid.
//
#define ERROR_FILE_INVALID               1006L

//
// MessageId: ERROR_FULLSCREEN_MODE
//
// MessageText:
//
// The requested operation cannot be performed in full-screen mode.
//
#define ERROR_FULLSCREEN_MODE            1007L

//
// MessageId: ERROR_NO_TOKEN
//
// MessageText:
//
// An attempt was made to reference a token that does not exist.
//
#define ERROR_NO_TOKEN                   1008L

//
// MessageId: ERROR_BADDB
//
// MessageText:
//
// The configuration registry database is corrupt.
//
#define ERROR_BADDB                      1009L

//
// MessageId: ERROR_BADKEY
//
// MessageText:
//
// The configuration registry key is invalid.
//
#define ERROR_BADKEY                     1010L

//
// MessageId: ERROR_CANTOPEN
//
// MessageText:
//
// The configuration registry key could not be opened.
//
#define ERROR_CANTOPEN                   1011L

//
// MessageId: ERROR_CANTREAD
//
// MessageText:
//
// The configuration registry key could not be read.
//
#define ERROR_CANTREAD                   1012L

//
// MessageId: ERROR_CANTWRITE
//
// MessageText:
//
// The configuration registry key could not be written.
//
#define ERROR_CANTWRITE                  1013L

//
// MessageId: ERROR_REGISTRY_RECOVERED
//
// MessageText:
//
// One of the files in the registry database had to be recovered by use of a log or alternate copy. The recovery was successful.
//
#define ERROR_REGISTRY_RECOVERED         1014L

//
// MessageId: ERROR_REGISTRY_CORRUPT
//
// MessageText:
//
// The registry is corrupted. The structure of one of the files containing registry data is corrupted, or the system's memory image of the file is corrupted, or the file could not be recovered because the alternate copy or log was absent or corrupted.
//
#define ERROR_REGISTRY_CORRUPT           1015L

//
// MessageId: ERROR_REGISTRY_IO_FAILED
//
// MessageText:
//
// An I/O operation initiated by the registry failed unrecoverably. The registry could not read in, or write out, or flush, one of the files that contain the system's image of the registry.
//
#define ERROR_REGISTRY_IO_FAILED         1016L

//
// MessageId: ERROR_NOT_REGISTRY_FILE
//
// MessageText:
//
// The system has attempted to load or restore a file into the registry, but the specified file is not in a registry file format.
//
#define ERROR_NOT_REGISTRY_FILE          1017L

//
// MessageId: ERROR_KEY_DELETED
//
// MessageText:
//
// Illegal operation attempted on a registry key that has been marked for deletion.
//
#define ERROR_KEY_DELETED                1018L

//
// MessageId: ERROR_NO_LOG_SPACE
//
// MessageText:
//
// System could not allocate the required space in a registry log.
//
#define ERROR_NO_LOG_SPACE               1019L

//
// MessageId: ERROR_KEY_HAS_CHILDREN
//
// MessageText:
//
// Cannot create a symbolic link in a registry key that already has subkeys or values.
//
#define ERROR_KEY_HAS_CHILDREN           1020L

//
// MessageId: ERROR_CHILD_MUST_BE_VOLATILE
//
// MessageText:
//
// Cannot create a stable subkey under a volatile parent key.
//
#define ERROR_CHILD_MUST_BE_VOLATILE     1021L

//
// MessageId: ERROR_NOTIFY_ENUM_DIR
//
// MessageText:
//
// A notify change request is being completed and the information is not being returned in the caller's buffer. The caller now needs to enumerate the files to find the changes.
//
#define ERROR_NOTIFY_ENUM_DIR            1022L

//
// MessageId: ERROR_DEPENDENT_SERVICES_RUNNING
//
// MessageText:
//
// A stop control has been sent to a service that other running services are dependent on.
//
#define ERROR_DEPENDENT_SERVICES_RUNNING 1051L

//
// MessageId: ERROR_INVALID_SERVICE_CONTROL
//
// MessageText:
//
// The requested control is not valid for this service.
//
#define ERROR_INVALID_SERVICE_CONTROL    1052L

//
// MessageId: ERROR_SERVICE_REQUEST_TIMEOUT
//
// MessageText:
//
// The service did not respond to the start or control request in a timely fashion.
//
#define ERROR_SERVICE_REQUEST_TIMEOUT    1053L

//
// MessageId: ERROR_SERVICE_NO_THREAD
//
// MessageText:
//
// A thread could not be created for the service.
//
#define ERROR_SERVICE_NO_THREAD          1054L

//
// MessageId: ERROR_SERVICE_DATABASE_LOCKED
//
// MessageText:
//
// The service database is locked.
//
#define ERROR_SERVICE_DATABASE_LOCKED    1055L

//
// MessageId: ERROR_SERVICE_ALREADY_RUNNING
//
// MessageText:
//
// An instance of the service is already running.
//
#define ERROR_SERVICE_ALREADY_RUNNING    1056L

//
// MessageId: ERROR_INVALID_SERVICE_ACCOUNT
//
// MessageText:
//
// The account name is invalid or does not exist, or the password is invalid for the account name specified.
//
#define ERROR_INVALID_SERVICE_ACCOUNT    1057L

//
// MessageId: ERROR_SERVICE_DISABLED
//
// MessageText:
//
// The service cannot be started, either because it is disabled or because it has no enabled devices associated with it.
//
#define ERROR_SERVICE_DISABLED           1058L

//
// MessageId: ERROR_CIRCULAR_DEPENDENCY
//
// MessageText:
//
// Circular service dependency was specified.
//
#define ERROR_CIRCULAR_DEPENDENCY        1059L

//
// MessageId: ERROR_SERVICE_DOES_NOT_EXIST
//
// MessageText:
//
// The specified service does not exist as an installed service.
//
#define ERROR_SERVICE_DOES_NOT_EXIST     1060L

//
// MessageId: ERROR_SERVICE_CANNOT_ACCEPT_CTRL
//
// MessageText:
//
// The service cannot accept control messages at this time.
//
#define ERROR_SERVICE_CANNOT_ACCEPT_CTRL 1061L

//
// MessageId: ERROR_SERVICE_NOT_ACTIVE
//
// MessageText:
//
// The service has not been started.
//
#define ERROR_SERVICE_NOT_ACTIVE         1062L

//
// MessageId: ERROR_FAILED_SERVICE_CONTROLLER_CONNECT
//
// MessageText:
//
// The service process could not connect to the service controller.
//
#define ERROR_FAILED_SERVICE_CONTROLLER_CONNECT 1063L

//
// MessageId: ERROR_EXCEPTION_IN_SERVICE
//
// MessageText:
//
// An exception occurred in the service when handling the control request.
//
#define ERROR_EXCEPTION_IN_SERVICE       1064L

//
// MessageId: ERROR_DATABASE_DOES_NOT_EXIST
//
// MessageText:
//
// The database specified does not exist.
//
#define ERROR_DATABASE_DOES_NOT_EXIST    1065L

//
// MessageId: ERROR_SERVICE_SPECIFIC_ERROR
//
// MessageText:
//
// The service has returned a service-specific error code.
//
#define ERROR_SERVICE_SPECIFIC_ERROR     1066L

//
// MessageId: ERROR_PROCESS_ABORTED
//
// MessageText:
//
// The process terminated unexpectedly.
//
#define ERROR_PROCESS_ABORTED            1067L

//
// MessageId: ERROR_SERVICE_DEPENDENCY_FAIL
//
// MessageText:
//
// The dependency service or group failed to start.
//
#define ERROR_SERVICE_DEPENDENCY_FAIL    1068L

//
// MessageId: ERROR_SERVICE_LOGON_FAILED
//
// MessageText:
//
// The service did not start due to a logon failure.
//
#define ERROR_SERVICE_LOGON_FAILED       1069L

//
// MessageId: ERROR_SERVICE_START_HANG
//
// MessageText:
//
// After starting, the service hung in a start-pending state.
//
#define ERROR_SERVICE_START_HANG         1070L

//
// MessageId: ERROR_INVALID_SERVICE_LOCK
//
// MessageText:
//
// The specified service database lock is invalid.
//
#define ERROR_INVALID_SERVICE_LOCK       1071L

//
// MessageId: ERROR_SERVICE_MARKED_FOR_DELETE
//
// MessageText:
//
// The specified service has been marked for deletion.
//
#define ERROR_SERVICE_MARKED_FOR_DELETE  1072L

//
// MessageId: ERROR_SERVICE_EXISTS
//
// MessageText:
//
// The specified service already exists.
//
#define ERROR_SERVICE_EXISTS             1073L

//
// MessageId: ERROR_ALREADY_RUNNING_LKG
//
// MessageText:
//
// The system is currently running with the last-known-good configuration.
//
#define ERROR_ALREADY_RUNNING_LKG        1074L

//
// MessageId: ERROR_SERVICE_DEPENDENCY_DELETED
//
// MessageText:
//
// The dependency service does not exist or has been marked for deletion.
//
#define ERROR_SERVICE_DEPENDENCY_DELETED 1075L

//
// MessageId: ERROR_BOOT_ALREADY_ACCEPTED
//
// MessageText:
//
// The current boot has already been accepted for use as the last-known-good control set.
//
#define ERROR_BOOT_ALREADY_ACCEPTED      1076L

//
// MessageId: ERROR_SERVICE_NEVER_STARTED
//
// MessageText:
//
// No attempts to start the service have been made since the last boot.
//
#define ERROR_SERVICE_NEVER_STARTED      1077L

//
// MessageId: ERROR_DUPLICATE_SERVICE_NAME
//
// MessageText:
//
// The name is already in use as either a service name or a service display name.
//
#define ERROR_DUPLICATE_SERVICE_NAME     1078L

//
// MessageId: ERROR_DIFFERENT_SERVICE_ACCOUNT
//
// MessageText:
//
// The account specified for this service is different from the account specified for other services running in the same process.
//
#define ERROR_DIFFERENT_SERVICE_ACCOUNT  1079L

//
// MessageId: ERROR_CANNOT_DETECT_DRIVER_FAILURE
//
// MessageText:
//
// Failure actions can only be set for Win32 services, not for drivers.
//
#define ERROR_CANNOT_DETECT_DRIVER_FAILURE 1080L

//
// MessageId: ERROR_CANNOT_DETECT_PROCESS_ABORT
//
// MessageText:
//
// This service runs in the same process as the service control manager.
// Therefore, the service control manager cannot take action if this service's process terminates unexpectedly.
//
#define ERROR_CANNOT_DETECT_PROCESS_ABORT 1081L

//
// MessageId: ERROR_NO_RECOVERY_PROGRAM
//
// MessageText:
//
// No recovery program has been configured for this service.
//
#define ERROR_NO_RECOVERY_PROGRAM        1082L

//
// MessageId: ERROR_SERVICE_NOT_IN_EXE
//
// MessageText:
//
// The executable program that this service is configured to run in does not implement the service.
//
#define ERROR_SERVICE_NOT_IN_EXE         1083L

//
// MessageId: ERROR_NOT_SAFEBOOT_SERVICE
//
// MessageText:
//
// This service cannot be started in Safe Mode
//
#define ERROR_NOT_SAFEBOOT_SERVICE       1084L

//
// MessageId: ERROR_END_OF_MEDIA
//
// MessageText:
//
// The physical end of the tape has been reached.
//
#define ERROR_END_OF_MEDIA               1100L

//
// MessageId: ERROR_FILEMARK_DETECTED
//
// MessageText:
//
// A tape access reached a filemark.
//
#define ERROR_FILEMARK_DETECTED          1101L

//
// MessageId: ERROR_BEGINNING_OF_MEDIA
//
// MessageText:
//
// The beginning of the tape or a partition was encountered.
//
#define ERROR_BEGINNING_OF_MEDIA         1102L

//
// MessageId: ERROR_SETMARK_DETECTED
//
// MessageText:
//
// A tape access reached the end of a set of files.
//
#define ERROR_SETMARK_DETECTED           1103L

//
// MessageId: ERROR_NO_DATA_DETECTED
//
// MessageText:
//
// No more data is on the tape.
//
#define ERROR_NO_DATA_DETECTED           1104L

//
// MessageId: ERROR_PARTITION_FAILURE
//
// MessageText:
//
// Tape could not be partitioned.
//
#define ERROR_PARTITION_FAILURE          1105L

//
// MessageId: ERROR_INVALID_BLOCK_LENGTH
//
// MessageText:
//
// When accessing a new tape of a multivolume partition, the current block size is incorrect.
//
#define ERROR_INVALID_BLOCK_LENGTH       1106L

//
// MessageId: ERROR_DEVICE_NOT_PARTITIONED
//
// MessageText:
//
// Tape partition information could not be found when loading a tape.
//
#define ERROR_DEVICE_NOT_PARTITIONED     1107L

//
// MessageId: ERROR_UNABLE_TO_LOCK_MEDIA
//
// MessageText:
//
// Unable to lock the media eject mechanism.
//
#define ERROR_UNABLE_TO_LOCK_MEDIA       1108L

//
// MessageId: ERROR_UNABLE_TO_UNLOAD_MEDIA
//
// MessageText:
//
// Unable to unload the media.
//
#define ERROR_UNABLE_TO_UNLOAD_MEDIA     1109L

//
// MessageId: ERROR_MEDIA_CHANGED
//
// MessageText:
//
// The media in the drive may have changed.
//
#define ERROR_MEDIA_CHANGED              1110L

//
// MessageId: ERROR_BUS_RESET
//
// MessageText:
//
// The I/O bus was reset.
//
#define ERROR_BUS_RESET                  1111L

//
// MessageId: ERROR_NO_MEDIA_IN_DRIVE
//
// MessageText:
//
// No media in drive.
//
#define ERROR_NO_MEDIA_IN_DRIVE          1112L

//
// MessageId: ERROR_NO_UNICODE_TRANSLATION
//
// MessageText:
//
// No mapping for the Unicode character exists in the target multi-byte code page.
//
#define ERROR_NO_UNICODE_TRANSLATION     1113L

//
// MessageId: ERROR_DLL_INIT_FAILED
//
// MessageText:
//
// A dynamic link library (DLL) initialization routine failed.
//
#define ERROR_DLL_INIT_FAILED            1114L

//
// MessageId: ERROR_SHUTDOWN_IN_PROGRESS
//
// MessageText:
//
// A system shutdown is in progress.
//
#define ERROR_SHUTDOWN_IN_PROGRESS       1115L

//
// MessageId: ERROR_NO_SHUTDOWN_IN_PROGRESS
//
// MessageText:
//
// Unable to abort the system shutdown because no shutdown was in progress.
//
#define ERROR_NO_SHUTDOWN_IN_PROGRESS    1116L

//
// MessageId: ERROR_IO_DEVICE
//
// MessageText:
//
// The request could not be performed because of an I/O device error.
//
#define ERROR_IO_DEVICE                  1117L

//
// MessageId: ERROR_SERIAL_NO_DEVICE
//
// MessageText:
//
// No serial device was successfully initialized. The serial driver will unload.
//
#define ERROR_SERIAL_NO_DEVICE           1118L

//
// MessageId: ERROR_IRQ_BUSY
//
// MessageText:
//
// Unable to open a device that was sharing an interrupt request (IRQ) with other devices. At least one other device that uses that IRQ was already opened.
//
#define ERROR_IRQ_BUSY                   1119L

//
// MessageId: ERROR_MORE_WRITES
//
// MessageText:
//
// A serial I/O operation was completed by another write to the serial port.
// (The IOCTL_SERIAL_XOFF_COUNTER reached zero.)
//
#define ERROR_MORE_WRITES                1120L

//
// MessageId: ERROR_COUNTER_TIMEOUT
//
// MessageText:
//
// A serial I/O operation completed because the timeout period expired.
// (The IOCTL_SERIAL_XOFF_COUNTER did not reach zero.)
//
#define ERROR_COUNTER_TIMEOUT            1121L

//
// MessageId: ERROR_FLOPPY_ID_MARK_NOT_FOUND
//
// MessageText:
//
// No ID address mark was found on the floppy disk.
//
#define ERROR_FLOPPY_ID_MARK_NOT_FOUND   1122L

//
// MessageId: ERROR_FLOPPY_WRONG_CYLINDER
//
// MessageText:
//
// Mismatch between the floppy disk sector ID field and the floppy disk controller track address.
//
#define ERROR_FLOPPY_WRONG_CYLINDER      1123L

//
// MessageId: ERROR_FLOPPY_UNKNOWN_ERROR
//
// MessageText:
//
// The floppy disk controller reported an error that is not recognized by the floppy disk driver.
//
#define ERROR_FLOPPY_UNKNOWN_ERROR       1124L

//
// MessageId: ERROR_FLOPPY_BAD_REGISTERS
//
// MessageText:
//
// The floppy disk controller returned inconsistent results in its registers.
//
#define ERROR_FLOPPY_BAD_REGISTERS       1125L

//
// MessageId: ERROR_DISK_RECALIBRATE_FAILED
//
// MessageText:
//
// While accessing the hard disk, a recalibrate operation failed, even after retries.
//
#define ERROR_DISK_RECALIBRATE_FAILED    1126L

//
// MessageId: ERROR_DISK_OPERATION_FAILED
//
// MessageText:
//
// While accessing the hard disk, a disk operation failed even after retries.
//
#define ERROR_DISK_OPERATION_FAILED      1127L

//
// MessageId: ERROR_DISK_RESET_FAILED
//
// MessageText:
//
// While accessing the hard disk, a disk controller reset was needed, but even that failed.
//
#define ERROR_DISK_RESET_FAILED          1128L

//
// MessageId: ERROR_EOM_OVERFLOW
//
// MessageText:
//
// Physical end of tape encountered.
//
#define ERROR_EOM_OVERFLOW               1129L

//
// MessageId: ERROR_NOT_ENOUGH_SERVER_MEMORY
//
// MessageText:
//
// Not enough server storage is available to process this command.
//
#define ERROR_NOT_ENOUGH_SERVER_MEMORY   1130L

//
// MessageId: ERROR_POSSIBLE_DEADLOCK
//
// MessageText:
//
// A potential deadlock condition has been detected.
//
#define ERROR_POSSIBLE_DEADLOCK          1131L

//
// MessageId: ERROR_MAPPED_ALIGNMENT
//
// MessageText:
//
// The base address or the file offset specified does not have the proper alignment.
//
#define ERROR_MAPPED_ALIGNMENT           1132L

//
// MessageId: ERROR_SET_POWER_STATE_VETOED
//
// MessageText:
//
// An attempt to change the system power state was vetoed by another application or driver.
//
#define ERROR_SET_POWER_STATE_VETOED     1140L

//
// MessageId: ERROR_SET_POWER_STATE_FAILED
//
// MessageText:
//
// The system BIOS failed an attempt to change the system power state.
//
#define ERROR_SET_POWER_STATE_FAILED     1141L

//
// MessageId: ERROR_TOO_MANY_LINKS
//
// MessageText:
//
// An attempt was made to create more links on a file than the file system supports.
//
#define ERROR_TOO_MANY_LINKS             1142L

//
// MessageId: ERROR_OLD_WIN_VERSION
//
// MessageText:
//
// The specified program requires a newer version of Windows.
//
#define ERROR_OLD_WIN_VERSION            1150L

//
// MessageId: ERROR_APP_WRONG_OS
//
// MessageText:
//
// The specified program is not a Windows or MS-DOS program.
//
#define ERROR_APP_WRONG_OS               1151L

//
// MessageId: ERROR_SINGLE_INSTANCE_APP
//
// MessageText:
//
// Cannot start more than one instance of the specified program.
//
#define ERROR_SINGLE_INSTANCE_APP        1152L

//
// MessageId: ERROR_RMODE_APP
//
// MessageText:
//
// The specified program was written for an earlier version of Windows.
//
#define ERROR_RMODE_APP                  1153L

//
// MessageId: ERROR_INVALID_DLL
//
// MessageText:
//
// One of the library files needed to run this application is damaged.
//
#define ERROR_INVALID_DLL                1154L

//
// MessageId: ERROR_NO_ASSOCIATION
//
// MessageText:
//
// No application is associated with the specified file for this operation.
//
#define ERROR_NO_ASSOCIATION             1155L

//
// MessageId: ERROR_DDE_FAIL
//
// MessageText:
//
// An error occurred in sending the command to the application.
//
#define ERROR_DDE_FAIL                   1156L

//
// MessageId: ERROR_DLL_NOT_FOUND
//
// MessageText:
//
// One of the library files needed to run this application cannot be found.
//
#define ERROR_DLL_NOT_FOUND              1157L

//
// MessageId: ERROR_NO_MORE_USER_HANDLES
//
// MessageText:
//
// The current process has used all of its system allowance of handles for Window Manager objects.
//
#define ERROR_NO_MORE_USER_HANDLES       1158L

//
// MessageId: ERROR_MESSAGE_SYNC_ONLY
//
// MessageText:
//
// The message can be used only with synchronous operations.
//
#define ERROR_MESSAGE_SYNC_ONLY          1159L

//
// MessageId: ERROR_SOURCE_ELEMENT_EMPTY
//
// MessageText:
//
// The indicated source element has no media.
//
#define ERROR_SOURCE_ELEMENT_EMPTY       1160L

//
// MessageId: ERROR_DESTINATION_ELEMENT_FULL
//
// MessageText:
//
// The indicated destination element already contains media.
//
#define ERROR_DESTINATION_ELEMENT_FULL   1161L

//
// MessageId: ERROR_ILLEGAL_ELEMENT_ADDRESS
//
// MessageText:
//
// The indicated element does not exist.
//
#define ERROR_ILLEGAL_ELEMENT_ADDRESS    1162L

//
// MessageId: ERROR_MAGAZINE_NOT_PRESENT
//
// MessageText:
//
// The indicated element is part of a magazine that is not present.
//
#define ERROR_MAGAZINE_NOT_PRESENT       1163L

//
// MessageId: ERROR_DEVICE_REINITIALIZATION_NEEDED
//
// MessageText:
//
// The indicated device requires reinitialization due to hardware errors.
//
#define ERROR_DEVICE_REINITIALIZATION_NEEDED 1164L    // dderror

//
// MessageId: ERROR_DEVICE_REQUIRES_CLEANING
//
// MessageText:
//
// The device has indicated that cleaning is required before further operations are attempted.
//
#define ERROR_DEVICE_REQUIRES_CLEANING   1165L

//
// MessageId: ERROR_DEVICE_DOOR_OPEN
//
// MessageText:
//
// The device has indicated that its door is open.
//
#define ERROR_DEVICE_DOOR_OPEN           1166L

//
// MessageId: ERROR_DEVICE_NOT_CONNECTED
//
// MessageText:
//
// The device is not connected.
//
#define ERROR_DEVICE_NOT_CONNECTED       1167L

//
// MessageId: ERROR_NOT_FOUND
//
// MessageText:
//
// Element not found.
//
#define ERROR_NOT_FOUND                  1168L

//
// MessageId: ERROR_NO_MATCH
//
// MessageText:
//
// There was no match for the specified key in the index.
//
#define ERROR_NO_MATCH                   1169L

//
// MessageId: ERROR_SET_NOT_FOUND
//
// MessageText:
//
// The property set specified does not exist on the object.
//
#define ERROR_SET_NOT_FOUND              1170L

//
// MessageId: ERROR_POINT_NOT_FOUND
//
// MessageText:
//
// The point passed to GetMouseMovePoints is not in the buffer.
//
#define ERROR_POINT_NOT_FOUND            1171L

//
// MessageId: ERROR_NO_TRACKING_SERVICE
//
// MessageText:
//
// The tracking (workstation) service is not running.
//
#define ERROR_NO_TRACKING_SERVICE        1172L

//
// MessageId: ERROR_NO_VOLUME_ID
//
// MessageText:
//
// The Volume ID could not be found.
//
#define ERROR_NO_VOLUME_ID               1173L

//
// MessageId: ERROR_UNABLE_TO_REMOVE_REPLACED
//
// MessageText:
//
// Unable to remove the file to be replaced.
//
#define ERROR_UNABLE_TO_REMOVE_REPLACED  1175L

//
// MessageId: ERROR_UNABLE_TO_MOVE_REPLACEMENT
//
// MessageText:
//
// Unable to move the replacement file to the file to be replaced. The file to be replaced has retained its original name.
//
#define ERROR_UNABLE_TO_MOVE_REPLACEMENT 1176L

//
// MessageId: ERROR_UNABLE_TO_MOVE_REPLACEMENT_2
//
// MessageText:
//
// Unable to move the replacement file to the file to be replaced. The file to be replaced has been renamed using the backup name.
//
#define ERROR_UNABLE_TO_MOVE_REPLACEMENT_2 1177L

//
// MessageId: ERROR_JOURNAL_DELETE_IN_PROGRESS
//
// MessageText:
//
// The volume change journal is being deleted.
//
#define ERROR_JOURNAL_DELETE_IN_PROGRESS 1178L

//
// MessageId: ERROR_JOURNAL_NOT_ACTIVE
//
// MessageText:
//
// The volume change journal is not active.
//
#define ERROR_JOURNAL_NOT_ACTIVE         1179L

//
// MessageId: ERROR_POTENTIAL_FILE_FOUND
//
// MessageText:
//
// A file was found, but it may not be the correct file.
//
#define ERROR_POTENTIAL_FILE_FOUND       1180L

//
// MessageId: ERROR_JOURNAL_ENTRY_DELETED
//
// MessageText:
//
// The journal entry has been deleted from the journal.
//
#define ERROR_JOURNAL_ENTRY_DELETED      1181L

//
// MessageId: ERROR_SHUTDOWN_IS_SCHEDULED
//
// MessageText:
//
// A system shutdown has already been scheduled.
//
#define ERROR_SHUTDOWN_IS_SCHEDULED      1190L

//
// MessageId: ERROR_SHUTDOWN_USERS_LOGGED_ON
//
// MessageText:
//
// The system shutdown cannot be initiated because there are other users logged on to the computer.
//
#define ERROR_SHUTDOWN_USERS_LOGGED_ON   1191L

//
// MessageId: ERROR_BAD_DEVICE
//
// MessageText:
//
// The specified device name is invalid.
//
#define ERROR_BAD_DEVICE                 1200L

//
// MessageId: ERROR_CONNECTION_UNAVAIL
//
// MessageText:
//
// The device is not currently connected but it is a remembered connection.
//
#define ERROR_CONNECTION_UNAVAIL         1201L

//
// MessageId: ERROR_DEVICE_ALREADY_REMEMBERED
//
// MessageText:
//
// The local device name has a remembered connection to another network resource.
//
#define ERROR_DEVICE_ALREADY_REMEMBERED  1202L

//
// MessageId: ERROR_NO_NET_OR_BAD_PATH
//
// MessageText:
//
// The network path was either typed incorrectly, does not exist, or the network provider is not currently available. Please try retyping the path or contact your network administrator.
//
#define ERROR_NO_NET_OR_BAD_PATH         1203L

//
// MessageId: ERROR_BAD_PROVIDER
//
// MessageText:
//
// The specified network provider name is invalid.
//
#define ERROR_BAD_PROVIDER               1204L

//
// MessageId: ERROR_CANNOT_OPEN_PROFILE
//
// MessageText:
//
// Unable to open the network connection profile.
//
#define ERROR_CANNOT_OPEN_PROFILE        1205L

//
// MessageId: ERROR_BAD_PROFILE
//
// MessageText:
//
// The network connection profile is corrupted.
//
#define ERROR_BAD_PROFILE                1206L

//
// MessageId: ERROR_NOT_CONTAINER
//
// MessageText:
//
// Cannot enumerate a noncontainer.
//
#define ERROR_NOT_CONTAINER              1207L

//
// MessageId: ERROR_EXTENDED_ERROR
//
// MessageText:
//
// An extended error has occurred.
//
#define ERROR_EXTENDED_ERROR             1208L

//
// MessageId: ERROR_INVALID_GROUPNAME
//
// MessageText:
//
// The format of the specified group name is invalid.
//
#define ERROR_INVALID_GROUPNAME          1209L

//
// MessageId: ERROR_INVALID_COMPUTERNAME
//
// MessageText:
//
// The format of the specified computer name is invalid.
//
#define ERROR_INVALID_COMPUTERNAME       1210L

//
// MessageId: ERROR_INVALID_EVENTNAME
//
// MessageText:
//
// The format of the specified event name is invalid.
//
#define ERROR_INVALID_EVENTNAME          1211L

//
// MessageId: ERROR_INVALID_DOMAINNAME
//
// MessageText:
//
// The format of the specified domain name is invalid.
//
#define ERROR_INVALID_DOMAINNAME         1212L

//
// MessageId: ERROR_INVALID_SERVICENAME
//
// MessageText:
//
// The format of the specified service name is invalid.
//
#define ERROR_INVALID_SERVICENAME        1213L

//
// MessageId: ERROR_INVALID_NETNAME
//
// MessageText:
//
// The format of the specified network name is invalid.
//
#define ERROR_INVALID_NETNAME            1214L

//
// MessageId: ERROR_INVALID_SHARENAME
//
// MessageText:
//
// The format of the specified share name is invalid.
//
#define ERROR_INVALID_SHARENAME          1215L

//
// MessageId: ERROR_INVALID_PASSWORDNAME
//
// MessageText:
//
// The format of the specified password is invalid.
//
#define ERROR_INVALID_PASSWORDNAME       1216L

//
// MessageId: ERROR_INVALID_MESSAGENAME
//
// MessageText:
//
// The format of the specified message name is invalid.
//
#define ERROR_INVALID_MESSAGENAME        1217L

//
// MessageId: ERROR_INVALID_MESSAGEDEST
//
// MessageText:
//
// The format of the specified message destination is invalid.
//
#define ERROR_INVALID_MESSAGEDEST        1218L

//
// MessageId: ERROR_SESSION_CREDENTIAL_CONFLICT
//
// MessageText:
//
// Multiple connections to a server or shared resource by the same user, using more than one user name, are not allowed. Disconnect all previous connections to the server or shared resource and try again.
//
#define ERROR_SESSION_CREDENTIAL_CONFLICT 1219L

//
// MessageId: ERROR_REMOTE_SESSION_LIMIT_EXCEEDED
//
// MessageText:
//
// An attempt was made to establish a session to a network server, but there are already too many sessions established to that server.
//
#define ERROR_REMOTE_SESSION_LIMIT_EXCEEDED 1220L

//
// MessageId: ERROR_DUP_DOMAINNAME
//
// MessageText:
//
// The workgroup or domain name is already in use by another computer on the network.
//
#define ERROR_DUP_DOMAINNAME             1221L

//
// MessageId: ERROR_NO_NETWORK
//
// MessageText:
//
// The network is not present or not started.
//
#define ERROR_NO_NETWORK                 1222L

//
// MessageId: ERROR_CANCELLED
//
// MessageText:
//
// The operation was canceled by the user.
//
#define ERROR_CANCELLED                  1223L

//
// MessageId: ERROR_USER_MAPPED_FILE
//
// MessageText:
//
// The requested operation cannot be performed on a file with a user-mapped section open.
//
#define ERROR_USER_MAPPED_FILE           1224L

//
// MessageId: ERROR_CONNECTION_REFUSED
//
// MessageText:
//
// The remote computer refused the network connection.
//
#define ERROR_CONNECTION_REFUSED         1225L

//
// MessageId: ERROR_GRACEFUL_DISCONNECT
//
// MessageText:
//
// The network connection was gracefully closed.
//
#define ERROR_GRACEFUL_DISCONNECT        1226L

//
// MessageId: ERROR_ADDRESS_ALREADY_ASSOCIATED
//
// MessageText:
//
// The network transport endpoint already has an address associated with it.
//
#define ERROR_ADDRESS_ALREADY_ASSOCIATED 1227L

//
// MessageId: ERROR_ADDRESS_NOT_ASSOCIATED
//
// MessageText:
//
// An address has not yet been associated with the network endpoint.
//
#define ERROR_ADDRESS_NOT_ASSOCIATED     1228L

//
// MessageId: ERROR_CONNECTION_INVALID
//
// MessageText:
//
// An operation was attempted on a nonexistent network connection.
//
#define ERROR_CONNECTION_INVALID         1229L

//
// MessageId: ERROR_CONNECTION_ACTIVE
//
// MessageText:
//
// An invalid operation was attempted on an active network connection.
//
#define ERROR_CONNECTION_ACTIVE          1230L

//
// MessageId: ERROR_NETWORK_UNREACHABLE
//
// MessageText:
//
// The network location cannot be reached. For information about network troubleshooting, see Windows Help.
//
#define ERROR_NETWORK_UNREACHABLE        1231L

//
// MessageId: ERROR_HOST_UNREACHABLE
//
// MessageText:
//
// The network location cannot be reached. For information about network troubleshooting, see Windows Help.
//
#define ERROR_HOST_UNREACHABLE           1232L

//
// MessageId: ERROR_PROTOCOL_UNREACHABLE
//
// MessageText:
//
// The network location cannot be reached. For information about network troubleshooting, see Windows Help.
//
#define ERROR_PROTOCOL_UNREACHABLE       1233L

//
// MessageId: ERROR_PORT_UNREACHABLE
//
// MessageText:
//
// No service is operating at the destination network endpoint on the remote system.
//
#define ERROR_PORT_UNREACHABLE           1234L

//
// MessageId: ERROR_REQUEST_ABORTED
//
// MessageText:
//
// The request was aborted.
//
#define ERROR_REQUEST_ABORTED            1235L

//
// MessageId: ERROR_CONNECTION_ABORTED
//
// MessageText:
//
// The network connection was aborted by the local system.
//
#define ERROR_CONNECTION_ABORTED         1236L

//
// MessageId: ERROR_RETRY
//
// MessageText:
//
// The operation could not be completed. A retry should be performed.
//
#define ERROR_RETRY                      1237L

//
// MessageId: ERROR_CONNECTION_COUNT_LIMIT
//
// MessageText:
//
// A connection to the server could not be made because the limit on the number of concurrent connections for this account has been reached.
//
#define ERROR_CONNECTION_COUNT_LIMIT     1238L

//
// MessageId: ERROR_LOGIN_TIME_RESTRICTION
//
// MessageText:
//
// Attempting to log in during an unauthorized time of day for this account.
//
#define ERROR_LOGIN_TIME_RESTRICTION     1239L

//
// MessageId: ERROR_LOGIN_WKSTA_RESTRICTION
//
// MessageText:
//
// The account is not authorized to log in from this station.
//
#define ERROR_LOGIN_WKSTA_RESTRICTION    1240L

//
// MessageId: ERROR_INCORRECT_ADDRESS
//
// MessageText:
//
// The network address could not be used for the operation requested.
//
#define ERROR_INCORRECT_ADDRESS          1241L

//
// MessageId: ERROR_ALREADY_REGISTERED
//
// MessageText:
//
// The service is already registered.
//
#define ERROR_ALREADY_REGISTERED         1242L

//
// MessageId: ERROR_SERVICE_NOT_FOUND
//
// MessageText:
//
// The specified service does not exist.
//
#define ERROR_SERVICE_NOT_FOUND          1243L

//
// MessageId: ERROR_NOT_AUTHENTICATED
//
// MessageText:
//
// The operation being requested was not performed because the user has not been authenticated.
//
#define ERROR_NOT_AUTHENTICATED          1244L

//
// MessageId: ERROR_NOT_LOGGED_ON
//
// MessageText:
//
// The operation being requested was not performed because the user has not logged on to the network.
// The specified service does not exist.
//
#define ERROR_NOT_LOGGED_ON              1245L

//
// MessageId: ERROR_CONTINUE
//
// MessageText:
//
// Continue with work in progress.
//
#define ERROR_CONTINUE                   1246L    // dderror

//
// MessageId: ERROR_ALREADY_INITIALIZED
//
// MessageText:
//
// An attempt was made to perform an initialization operation when initialization has already been completed.
//
#define ERROR_ALREADY_INITIALIZED        1247L

//
// MessageId: ERROR_NO_MORE_DEVICES
//
// MessageText:
//
// No more local devices.
//
#define ERROR_NO_MORE_DEVICES            1248L    // dderror

//
// MessageId: ERROR_NO_SUCH_SITE
//
// MessageText:
//
// The specified site does not exist.
//
#define ERROR_NO_SUCH_SITE               1249L

//
// MessageId: ERROR_DOMAIN_CONTROLLER_EXISTS
//
// MessageText:
//
// A domain controller with the specified name already exists.
//
#define ERROR_DOMAIN_CONTROLLER_EXISTS   1250L

//
// MessageId: ERROR_ONLY_IF_CONNECTED
//
// MessageText:
//
// This operation is supported only when you are connected to the server.
//
#define ERROR_ONLY_IF_CONNECTED          1251L

//
// MessageId: ERROR_OVERRIDE_NOCHANGES
//
// MessageText:
//
// The group policy framework should call the extension even if there are no changes.
//
#define ERROR_OVERRIDE_NOCHANGES         1252L

//
// MessageId: ERROR_BAD_USER_PROFILE
//
// MessageText:
//
// The specified user does not have a valid profile.
//
#define ERROR_BAD_USER_PROFILE           1253L

//
// MessageId: ERROR_NOT_SUPPORTED_ON_SBS
//
// MessageText:
//
// This operation is not supported on a computer running Windows Server 2003 for Small Business Server
//
#define ERROR_NOT_SUPPORTED_ON_SBS       1254L

//
// MessageId: ERROR_SERVER_SHUTDOWN_IN_PROGRESS
//
// MessageText:
//
// The server machine is shutting down.
//
#define ERROR_SERVER_SHUTDOWN_IN_PROGRESS 1255L

//
// MessageId: ERROR_HOST_DOWN
//
// MessageText:
//
// The remote system is not available. For information about network troubleshooting, see Windows Help.
//
#define ERROR_HOST_DOWN                  1256L

//
// MessageId: ERROR_NON_ACCOUNT_SID
//
// MessageText:
//
// The security identifier provided is not from an account domain.
//
#define ERROR_NON_ACCOUNT_SID            1257L

//
// MessageId: ERROR_NON_DOMAIN_SID
//
// MessageText:
//
// The security identifier provided does not have a domain component.
//
#define ERROR_NON_DOMAIN_SID             1258L

//
// MessageId: ERROR_APPHELP_BLOCK
//
// MessageText:
//
// AppHelp dialog canceled thus preventing the application from starting.
//
#define ERROR_APPHELP_BLOCK              1259L

//
// MessageId: ERROR_ACCESS_DISABLED_BY_POLICY
//
// MessageText:
//
// This program is blocked by group policy. For more information, contact your system administrator.
//
#define ERROR_ACCESS_DISABLED_BY_POLICY  1260L

//
// MessageId: ERROR_REG_NAT_CONSUMPTION
//
// MessageText:
//
// A program attempt to use an invalid register value. Normally caused by an uninitialized register. This error is Itanium specific.
//
#define ERROR_REG_NAT_CONSUMPTION        1261L

//
// MessageId: ERROR_CSCSHARE_OFFLINE
//
// MessageText:
//
// The share is currently offline or does not exist.
//
#define ERROR_CSCSHARE_OFFLINE           1262L

//
// MessageId: ERROR_PKINIT_FAILURE
//
// MessageText:
//
// The kerberos protocol encountered an error while validating the KDC certificate during smartcard logon. There is more information in the system event log.
//
#define ERROR_PKINIT_FAILURE             1263L

//
// MessageId: ERROR_SMARTCARD_SUBSYSTEM_FAILURE
//
// MessageText:
//
// The kerberos protocol encountered an error while attempting to utilize the smartcard subsystem.
//
#define ERROR_SMARTCARD_SUBSYSTEM_FAILURE 1264L

//
// MessageId: ERROR_DOWNGRADE_DETECTED
//
// MessageText:
//
// The system detected a possible attempt to compromise security. Please ensure that you can contact the server that authenticated you.
//
#define ERROR_DOWNGRADE_DETECTED         1265L

//
// Do not use ID's 1266 - 1270 as the symbolicNames have been moved to SEC_E_*
//
//
// MessageId: ERROR_MACHINE_LOCKED
//
// MessageText:
//
// The machine is locked and cannot be shut down without the force option.
//
#define ERROR_MACHINE_LOCKED             1271L

//
// MessageId: ERROR_CALLBACK_SUPPLIED_INVALID_DATA
//
// MessageText:
//
// An application-defined callback gave invalid data when called.
//
#define ERROR_CALLBACK_SUPPLIED_INVALID_DATA 1273L

//
// MessageId: ERROR_SYNC_FOREGROUND_REFRESH_REQUIRED
//
// MessageText:
//
// The group policy framework should call the extension in the synchronous foreground policy refresh.
//
#define ERROR_SYNC_FOREGROUND_REFRESH_REQUIRED 1274L

//
// MessageId: ERROR_DRIVER_BLOCKED
//
// MessageText:
//
// This driver has been blocked from loading
//
#define ERROR_DRIVER_BLOCKED             1275L

//
// MessageId: ERROR_INVALID_IMPORT_OF_NON_DLL
//
// MessageText:
//
// A dynamic link library (DLL) referenced a module that was neither a DLL nor the process's executable image.
//
#define ERROR_INVALID_IMPORT_OF_NON_DLL  1276L

//
// MessageId: ERROR_ACCESS_DISABLED_WEBBLADE
//
// MessageText:
//
// Windows cannot open this program since it has been disabled.
//
#define ERROR_ACCESS_DISABLED_WEBBLADE   1277L

//
// MessageId: ERROR_ACCESS_DISABLED_WEBBLADE_TAMPER
//
// MessageText:
//
// Windows cannot open this program because the license enforcement system has been tampered with or become corrupted.
//
#define ERROR_ACCESS_DISABLED_WEBBLADE_TAMPER 1278L

//
// MessageId: ERROR_RECOVERY_FAILURE
//
// MessageText:
//
// A transaction recover failed.
//
#define ERROR_RECOVERY_FAILURE           1279L

//
// MessageId: ERROR_ALREADY_FIBER
//
// MessageText:
//
// The current thread has already been converted to a fiber.
//
#define ERROR_ALREADY_FIBER              1280L

//
// MessageId: ERROR_ALREADY_THREAD
//
// MessageText:
//
// The current thread has already been converted from a fiber.
//
#define ERROR_ALREADY_THREAD             1281L

//
// MessageId: ERROR_STACK_BUFFER_OVERRUN
//
// MessageText:
//
// The system detected an overrun of a stack-based buffer in this application. This overrun could potentially allow a malicious user to gain control of this application.
//
#define ERROR_STACK_BUFFER_OVERRUN       1282L

//
// MessageId: ERROR_PARAMETER_QUOTA_EXCEEDED
//
// MessageText:
//
// Data present in one of the parameters is more than the function can operate on.
//
#define ERROR_PARAMETER_QUOTA_EXCEEDED   1283L

//
// MessageId: ERROR_DEBUGGER_INACTIVE
//
// MessageText:
//
// An attempt to do an operation on a debug object failed because the object is in the process of being deleted.
//
#define ERROR_DEBUGGER_INACTIVE          1284L

//
// MessageId: ERROR_DELAY_LOAD_FAILED
//
// MessageText:
//
// An attempt to delay-load a .dll or get a function address in a delay-loaded .dll failed.
//
#define ERROR_DELAY_LOAD_FAILED          1285L

//
// MessageId: ERROR_VDM_DISALLOWED
//
// MessageText:
//
// %1 is a 16-bit application. You do not have permissions to execute 16-bit applications. Check your permissions with your system administrator.
//
#define ERROR_VDM_DISALLOWED             1286L

//
// MessageId: ERROR_UNIDENTIFIED_ERROR
//
// MessageText:
//
// Insufficient information exists to identify the cause of failure.
//
#define ERROR_UNIDENTIFIED_ERROR         1287L

//
// MessageId: ERROR_INVALID_CRUNTIME_PARAMETER
//
// MessageText:
//
// The parameter passed to a C runtime function is incorrect.
//
#define ERROR_INVALID_CRUNTIME_PARAMETER 1288L

//
// MessageId: ERROR_BEYOND_VDL
//
// MessageText:
//
// The operation occurred beyond the valid data length of the file.
//
#define ERROR_BEYOND_VDL                 1289L

//
// MessageId: ERROR_INCOMPATIBLE_SERVICE_SID_TYPE
//
// MessageText:
//
// The service start failed since one or more services in the same process have an incompatible service SID type setting. A service with restricted service SID type can only coexist in the same process with other services with a restricted SID type. If the service SID type for this service was just configured, the hosting process must be restarted in order to start this service.
//
#define ERROR_INCOMPATIBLE_SERVICE_SID_TYPE 1290L

//
// MessageId: ERROR_DRIVER_PROCESS_TERMINATED
//
// MessageText:
//
// The process hosting the driver for this device has been terminated.
//
#define ERROR_DRIVER_PROCESS_TERMINATED  1291L

//
// MessageId: ERROR_IMPLEMENTATION_LIMIT
//
// MessageText:
//
// An operation attempted to exceed an implementation-defined limit.
//
#define ERROR_IMPLEMENTATION_LIMIT       1292L

//
// MessageId: ERROR_PROCESS_IS_PROTECTED
//
// MessageText:
//
// Either the target process, or the target thread's containing process, is a protected process.
//
#define ERROR_PROCESS_IS_PROTECTED       1293L

//
// MessageId: ERROR_SERVICE_NOTIFY_CLIENT_LAGGING
//
// MessageText:
//
// The service notification client is lagging too far behind the current state of services in the machine.
//
#define ERROR_SERVICE_NOTIFY_CLIENT_LAGGING 1294L

//
// MessageId: ERROR_DISK_QUOTA_EXCEEDED
//
// MessageText:
//
// The requested file operation failed because the storage quota was exceeded.
// To free up disk space, move files to a different location or delete unnecessary files. For more information, contact your system administrator.
//
#define ERROR_DISK_QUOTA_EXCEEDED        1295L

//
// MessageId: ERROR_CONTENT_BLOCKED
//
// MessageText:
//
// The requested file operation failed because the storage policy blocks that type of file. For more information, contact your system administrator.
//
#define ERROR_CONTENT_BLOCKED            1296L

//
// MessageId: ERROR_INCOMPATIBLE_SERVICE_PRIVILEGE
//
// MessageText:
//
// A privilege that the service requires to function properly does not exist in the service account configuration.
// You may use the Services Microsoft Management Console (MMC) snap-in (services.msc) and the Local Security Settings MMC snap-in (secpol.msc) to view the service configuration and the account configuration.
//
#define ERROR_INCOMPATIBLE_SERVICE_PRIVILEGE 1297L


///////////////////////////////////////////////////
//                                               //
//             SECURITY Error codes              //
//                                               //
//                 1299 to 1399                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_INVALID_LABEL
//
// MessageText:
//
// Indicates a particular Security ID may not be assigned as the label of an object.
//
#define ERROR_INVALID_LABEL              1299L

//
// MessageId: ERROR_NOT_ALL_ASSIGNED
//
// MessageText:
//
// Not all privileges or groups referenced are assigned to the caller.
//
#define ERROR_NOT_ALL_ASSIGNED           1300L

//
// MessageId: ERROR_SOME_NOT_MAPPED
//
// MessageText:
//
// Some mapping between account names and security IDs was not done.
//
#define ERROR_SOME_NOT_MAPPED            1301L

//
// MessageId: ERROR_NO_QUOTAS_FOR_ACCOUNT
//
// MessageText:
//
// No system quota limits are specifically set for this account.
//
#define ERROR_NO_QUOTAS_FOR_ACCOUNT      1302L

//
// MessageId: ERROR_LOCAL_USER_SESSION_KEY
//
// MessageText:
//
// No encryption key is available. A well-known encryption key was returned.
//
#define ERROR_LOCAL_USER_SESSION_KEY     1303L

//
// MessageId: ERROR_NULL_LM_PASSWORD
//
// MessageText:
//
// The password is too complex to be converted to a LAN Manager password. The LAN Manager password returned is a NULL string.
//
#define ERROR_NULL_LM_PASSWORD           1304L

//
// MessageId: ERROR_UNKNOWN_REVISION
//
// MessageText:
//
// The revision level is unknown.
//
#define ERROR_UNKNOWN_REVISION           1305L

//
// MessageId: ERROR_REVISION_MISMATCH
//
// MessageText:
//
// Indicates two revision levels are incompatible.
//
#define ERROR_REVISION_MISMATCH          1306L

//
// MessageId: ERROR_INVALID_OWNER
//
// MessageText:
//
// This security ID may not be assigned as the owner of this object.
//
#define ERROR_INVALID_OWNER              1307L

//
// MessageId: ERROR_INVALID_PRIMARY_GROUP
//
// MessageText:
//
// This security ID may not be assigned as the primary group of an object.
//
#define ERROR_INVALID_PRIMARY_GROUP      1308L

//
// MessageId: ERROR_NO_IMPERSONATION_TOKEN
//
// MessageText:
//
// An attempt has been made to operate on an impersonation token by a thread that is not currently impersonating a client.
//
#define ERROR_NO_IMPERSONATION_TOKEN     1309L

//
// MessageId: ERROR_CANT_DISABLE_MANDATORY
//
// MessageText:
//
// The group may not be disabled.
//
#define ERROR_CANT_DISABLE_MANDATORY     1310L

//
// MessageId: ERROR_NO_LOGON_SERVERS
//
// MessageText:
//
// There are currently no logon servers available to service the logon request.
//
#define ERROR_NO_LOGON_SERVERS           1311L

//
// MessageId: ERROR_NO_SUCH_LOGON_SESSION
//
// MessageText:
//
// A specified logon session does not exist. It may already have been terminated.
//
#define ERROR_NO_SUCH_LOGON_SESSION      1312L

//
// MessageId: ERROR_NO_SUCH_PRIVILEGE
//
// MessageText:
//
// A specified privilege does not exist.
//
#define ERROR_NO_SUCH_PRIVILEGE          1313L

//
// MessageId: ERROR_PRIVILEGE_NOT_HELD
//
// MessageText:
//
// A required privilege is not held by the client.
//
#define ERROR_PRIVILEGE_NOT_HELD         1314L

//
// MessageId: ERROR_INVALID_ACCOUNT_NAME
//
// MessageText:
//
// The name provided is not a properly formed account name.
//
#define ERROR_INVALID_ACCOUNT_NAME       1315L

//
// MessageId: ERROR_USER_EXISTS
//
// MessageText:
//
// The specified account already exists.
//
#define ERROR_USER_EXISTS                1316L

//
// MessageId: ERROR_NO_SUCH_USER
//
// MessageText:
//
// The specified account does not exist.
//
#define ERROR_NO_SUCH_USER               1317L

//
// MessageId: ERROR_GROUP_EXISTS
//
// MessageText:
//
// The specified group already exists.
//
#define ERROR_GROUP_EXISTS               1318L

//
// MessageId: ERROR_NO_SUCH_GROUP
//
// MessageText:
//
// The specified group does not exist.
//
#define ERROR_NO_SUCH_GROUP              1319L

//
// MessageId: ERROR_MEMBER_IN_GROUP
//
// MessageText:
//
// Either the specified user account is already a member of the specified group, or the specified group cannot be deleted because it contains a member.
//
#define ERROR_MEMBER_IN_GROUP            1320L

//
// MessageId: ERROR_MEMBER_NOT_IN_GROUP
//
// MessageText:
//
// The specified user account is not a member of the specified group account.
//
#define ERROR_MEMBER_NOT_IN_GROUP        1321L

//
// MessageId: ERROR_LAST_ADMIN
//
// MessageText:
//
// The last remaining administration account cannot be disabled or deleted.
//
#define ERROR_LAST_ADMIN                 1322L

//
// MessageId: ERROR_WRONG_PASSWORD
//
// MessageText:
//
// Unable to update the password. The value provided as the current password is incorrect.
//
#define ERROR_WRONG_PASSWORD             1323L

//
// MessageId: ERROR_ILL_FORMED_PASSWORD
//
// MessageText:
//
// Unable to update the password. The value provided for the new password contains values that are not allowed in passwords.
//
#define ERROR_ILL_FORMED_PASSWORD        1324L

//
// MessageId: ERROR_PASSWORD_RESTRICTION
//
// MessageText:
//
// Unable to update the password. The value provided for the new password does not meet the length, complexity, or history requirements of the domain.
//
#define ERROR_PASSWORD_RESTRICTION       1325L

//
// MessageId: ERROR_LOGON_FAILURE
//
// MessageText:
//
// Logon failure: unknown user name or bad password.
//
#define ERROR_LOGON_FAILURE              1326L

//
// MessageId: ERROR_ACCOUNT_RESTRICTION
//
// MessageText:
//
// Logon failure: user account restriction. Possible reasons are blank passwords not allowed, logon hour restrictions, or a policy restriction has been enforced.
//
#define ERROR_ACCOUNT_RESTRICTION        1327L

//
// MessageId: ERROR_INVALID_LOGON_HOURS
//
// MessageText:
//
// Logon failure: account logon time restriction violation.
//
#define ERROR_INVALID_LOGON_HOURS        1328L

//
// MessageId: ERROR_INVALID_WORKSTATION
//
// MessageText:
//
// Logon failure: user not allowed to log on to this computer.
//
#define ERROR_INVALID_WORKSTATION        1329L

//
// MessageId: ERROR_PASSWORD_EXPIRED
//
// MessageText:
//
// Logon failure: the specified account password has expired.
//
#define ERROR_PASSWORD_EXPIRED           1330L

//
// MessageId: ERROR_ACCOUNT_DISABLED
//
// MessageText:
//
// Logon failure: account currently disabled.
//
#define ERROR_ACCOUNT_DISABLED           1331L

//
// MessageId: ERROR_NONE_MAPPED
//
// MessageText:
//
// No mapping between account names and security IDs was done.
//
#define ERROR_NONE_MAPPED                1332L

//
// MessageId: ERROR_TOO_MANY_LUIDS_REQUESTED
//
// MessageText:
//
// Too many local user identifiers (LUIDs) were requested at one time.
//
#define ERROR_TOO_MANY_LUIDS_REQUESTED   1333L

//
// MessageId: ERROR_LUIDS_EXHAUSTED
//
// MessageText:
//
// No more local user identifiers (LUIDs) are available.
//
#define ERROR_LUIDS_EXHAUSTED            1334L

//
// MessageId: ERROR_INVALID_SUB_AUTHORITY
//
// MessageText:
//
// The subauthority part of a security ID is invalid for this particular use.
//
#define ERROR_INVALID_SUB_AUTHORITY      1335L

//
// MessageId: ERROR_INVALID_ACL
//
// MessageText:
//
// The access control list (ACL) structure is invalid.
//
#define ERROR_INVALID_ACL                1336L

//
// MessageId: ERROR_INVALID_SID
//
// MessageText:
//
// The security ID structure is invalid.
//
#define ERROR_INVALID_SID                1337L

//
// MessageId: ERROR_INVALID_SECURITY_DESCR
//
// MessageText:
//
// The security descriptor structure is invalid.
//
#define ERROR_INVALID_SECURITY_DESCR     1338L

//
// MessageId: ERROR_BAD_INHERITANCE_ACL
//
// MessageText:
//
// The inherited access control list (ACL) or access control entry (ACE) could not be built.
//
#define ERROR_BAD_INHERITANCE_ACL        1340L

//
// MessageId: ERROR_SERVER_DISABLED
//
// MessageText:
//
// The server is currently disabled.
//
#define ERROR_SERVER_DISABLED            1341L

//
// MessageId: ERROR_SERVER_NOT_DISABLED
//
// MessageText:
//
// The server is currently enabled.
//
#define ERROR_SERVER_NOT_DISABLED        1342L

//
// MessageId: ERROR_INVALID_ID_AUTHORITY
//
// MessageText:
//
// The value provided was an invalid value for an identifier authority.
//
#define ERROR_INVALID_ID_AUTHORITY       1343L

//
// MessageId: ERROR_ALLOTTED_SPACE_EXCEEDED
//
// MessageText:
//
// No more memory is available for security information updates.
//
#define ERROR_ALLOTTED_SPACE_EXCEEDED    1344L

//
// MessageId: ERROR_INVALID_GROUP_ATTRIBUTES
//
// MessageText:
//
// The specified attributes are invalid, or incompatible with the attributes for the group as a whole.
//
#define ERROR_INVALID_GROUP_ATTRIBUTES   1345L

//
// MessageId: ERROR_BAD_IMPERSONATION_LEVEL
//
// MessageText:
//
// Either a required impersonation level was not provided, or the provided impersonation level is invalid.
//
#define ERROR_BAD_IMPERSONATION_LEVEL    1346L

//
// MessageId: ERROR_CANT_OPEN_ANONYMOUS
//
// MessageText:
//
// Cannot open an anonymous level security token.
//
#define ERROR_CANT_OPEN_ANONYMOUS        1347L

//
// MessageId: ERROR_BAD_VALIDATION_CLASS
//
// MessageText:
//
// The validation information class requested was invalid.
//
#define ERROR_BAD_VALIDATION_CLASS       1348L

//
// MessageId: ERROR_BAD_TOKEN_TYPE
//
// MessageText:
//
// The type of the token is inappropriate for its attempted use.
//
#define ERROR_BAD_TOKEN_TYPE             1349L

//
// MessageId: ERROR_NO_SECURITY_ON_OBJECT
//
// MessageText:
//
// Unable to perform a security operation on an object that has no associated security.
//
#define ERROR_NO_SECURITY_ON_OBJECT      1350L

//
// MessageId: ERROR_CANT_ACCESS_DOMAIN_INFO
//
// MessageText:
//
// Configuration information could not be read from the domain controller, either because the machine is unavailable, or access has been denied.
//
#define ERROR_CANT_ACCESS_DOMAIN_INFO    1351L

//
// MessageId: ERROR_INVALID_SERVER_STATE
//
// MessageText:
//
// The security account manager (SAM) or local security authority (LSA) server was in the wrong state to perform the security operation.
//
#define ERROR_INVALID_SERVER_STATE       1352L

//
// MessageId: ERROR_INVALID_DOMAIN_STATE
//
// MessageText:
//
// The domain was in the wrong state to perform the security operation.
//
#define ERROR_INVALID_DOMAIN_STATE       1353L

//
// MessageId: ERROR_INVALID_DOMAIN_ROLE
//
// MessageText:
//
// This operation is only allowed for the Primary Domain Controller of the domain.
//
#define ERROR_INVALID_DOMAIN_ROLE        1354L

//
// MessageId: ERROR_NO_SUCH_DOMAIN
//
// MessageText:
//
// The specified domain either does not exist or could not be contacted.
//
#define ERROR_NO_SUCH_DOMAIN             1355L

//
// MessageId: ERROR_DOMAIN_EXISTS
//
// MessageText:
//
// The specified domain already exists.
//
#define ERROR_DOMAIN_EXISTS              1356L

//
// MessageId: ERROR_DOMAIN_LIMIT_EXCEEDED
//
// MessageText:
//
// An attempt was made to exceed the limit on the number of domains per server.
//
#define ERROR_DOMAIN_LIMIT_EXCEEDED      1357L

//
// MessageId: ERROR_INTERNAL_DB_CORRUPTION
//
// MessageText:
//
// Unable to complete the requested operation because of either a catastrophic media failure or a data structure corruption on the disk.
//
#define ERROR_INTERNAL_DB_CORRUPTION     1358L

//
// MessageId: ERROR_INTERNAL_ERROR
//
// MessageText:
//
// An internal error occurred.
//
#define ERROR_INTERNAL_ERROR             1359L

//
// MessageId: ERROR_GENERIC_NOT_MAPPED
//
// MessageText:
//
// Generic access types were contained in an access mask which should already be mapped to nongeneric types.
//
#define ERROR_GENERIC_NOT_MAPPED         1360L

//
// MessageId: ERROR_BAD_DESCRIPTOR_FORMAT
//
// MessageText:
//
// A security descriptor is not in the right format (absolute or self-relative).
//
#define ERROR_BAD_DESCRIPTOR_FORMAT      1361L

//
// MessageId: ERROR_NOT_LOGON_PROCESS
//
// MessageText:
//
// The requested action is restricted for use by logon processes only. The calling process has not registered as a logon process.
//
#define ERROR_NOT_LOGON_PROCESS          1362L

//
// MessageId: ERROR_LOGON_SESSION_EXISTS
//
// MessageText:
//
// Cannot start a new logon session with an ID that is already in use.
//
#define ERROR_LOGON_SESSION_EXISTS       1363L

//
// MessageId: ERROR_NO_SUCH_PACKAGE
//
// MessageText:
//
// A specified authentication package is unknown.
//
#define ERROR_NO_SUCH_PACKAGE            1364L

//
// MessageId: ERROR_BAD_LOGON_SESSION_STATE
//
// MessageText:
//
// The logon session is not in a state that is consistent with the requested operation.
//
#define ERROR_BAD_LOGON_SESSION_STATE    1365L

//
// MessageId: ERROR_LOGON_SESSION_COLLISION
//
// MessageText:
//
// The logon session ID is already in use.
//
#define ERROR_LOGON_SESSION_COLLISION    1366L

//
// MessageId: ERROR_INVALID_LOGON_TYPE
//
// MessageText:
//
// A logon request contained an invalid logon type value.
//
#define ERROR_INVALID_LOGON_TYPE         1367L

//
// MessageId: ERROR_CANNOT_IMPERSONATE
//
// MessageText:
//
// Unable to impersonate using a named pipe until data has been read from that pipe.
//
#define ERROR_CANNOT_IMPERSONATE         1368L

//
// MessageId: ERROR_RXACT_INVALID_STATE
//
// MessageText:
//
// The transaction state of a registry subtree is incompatible with the requested operation.
//
#define ERROR_RXACT_INVALID_STATE        1369L

//
// MessageId: ERROR_RXACT_COMMIT_FAILURE
//
// MessageText:
//
// An internal security database corruption has been encountered.
//
#define ERROR_RXACT_COMMIT_FAILURE       1370L

//
// MessageId: ERROR_SPECIAL_ACCOUNT
//
// MessageText:
//
// Cannot perform this operation on built-in accounts.
//
#define ERROR_SPECIAL_ACCOUNT            1371L

//
// MessageId: ERROR_SPECIAL_GROUP
//
// MessageText:
//
// Cannot perform this operation on this built-in special group.
//
#define ERROR_SPECIAL_GROUP              1372L

//
// MessageId: ERROR_SPECIAL_USER
//
// MessageText:
//
// Cannot perform this operation on this built-in special user.
//
#define ERROR_SPECIAL_USER               1373L

//
// MessageId: ERROR_MEMBERS_PRIMARY_GROUP
//
// MessageText:
//
// The user cannot be removed from a group because the group is currently the user's primary group.
//
#define ERROR_MEMBERS_PRIMARY_GROUP      1374L

//
// MessageId: ERROR_TOKEN_ALREADY_IN_USE
//
// MessageText:
//
// The token is already in use as a primary token.
//
#define ERROR_TOKEN_ALREADY_IN_USE       1375L

//
// MessageId: ERROR_NO_SUCH_ALIAS
//
// MessageText:
//
// The specified local group does not exist.
//
#define ERROR_NO_SUCH_ALIAS              1376L

//
// MessageId: ERROR_MEMBER_NOT_IN_ALIAS
//
// MessageText:
//
// The specified account name is not a member of the group.
//
#define ERROR_MEMBER_NOT_IN_ALIAS        1377L

//
// MessageId: ERROR_MEMBER_IN_ALIAS
//
// MessageText:
//
// The specified account name is already a member of the group.
//
#define ERROR_MEMBER_IN_ALIAS            1378L

//
// MessageId: ERROR_ALIAS_EXISTS
//
// MessageText:
//
// The specified local group already exists.
//
#define ERROR_ALIAS_EXISTS               1379L

//
// MessageId: ERROR_LOGON_NOT_GRANTED
//
// MessageText:
//
// Logon failure: the user has not been granted the requested logon type at this computer.
//
#define ERROR_LOGON_NOT_GRANTED          1380L

//
// MessageId: ERROR_TOO_MANY_SECRETS
//
// MessageText:
//
// The maximum number of secrets that may be stored in a single system has been exceeded.
//
#define ERROR_TOO_MANY_SECRETS           1381L

//
// MessageId: ERROR_SECRET_TOO_LONG
//
// MessageText:
//
// The length of a secret exceeds the maximum length allowed.
//
#define ERROR_SECRET_TOO_LONG            1382L

//
// MessageId: ERROR_INTERNAL_DB_ERROR
//
// MessageText:
//
// The local security authority database contains an internal inconsistency.
//
#define ERROR_INTERNAL_DB_ERROR          1383L

//
// MessageId: ERROR_TOO_MANY_CONTEXT_IDS
//
// MessageText:
//
// During a logon attempt, the user's security context accumulated too many security IDs.
//
#define ERROR_TOO_MANY_CONTEXT_IDS       1384L

//
// MessageId: ERROR_LOGON_TYPE_NOT_GRANTED
//
// MessageText:
//
// Logon failure: the user has not been granted the requested logon type at this computer.
//
#define ERROR_LOGON_TYPE_NOT_GRANTED     1385L

//
// MessageId: ERROR_NT_CROSS_ENCRYPTION_REQUIRED
//
// MessageText:
//
// A cross-encrypted password is necessary to change a user password.
//
#define ERROR_NT_CROSS_ENCRYPTION_REQUIRED 1386L

//
// MessageId: ERROR_NO_SUCH_MEMBER
//
// MessageText:
//
// A member could not be added to or removed from the local group because the member does not exist.
//
#define ERROR_NO_SUCH_MEMBER             1387L

//
// MessageId: ERROR_INVALID_MEMBER
//
// MessageText:
//
// A new member could not be added to a local group because the member has the wrong account type.
//
#define ERROR_INVALID_MEMBER             1388L

//
// MessageId: ERROR_TOO_MANY_SIDS
//
// MessageText:
//
// Too many security IDs have been specified.
//
#define ERROR_TOO_MANY_SIDS              1389L

//
// MessageId: ERROR_LM_CROSS_ENCRYPTION_REQUIRED
//
// MessageText:
//
// A cross-encrypted password is necessary to change this user password.
//
#define ERROR_LM_CROSS_ENCRYPTION_REQUIRED 1390L

//
// MessageId: ERROR_NO_INHERITANCE
//
// MessageText:
//
// Indicates an ACL contains no inheritable components.
//
#define ERROR_NO_INHERITANCE             1391L

//
// MessageId: ERROR_FILE_CORRUPT
//
// MessageText:
//
// The file or directory is corrupted and unreadable.
//
#define ERROR_FILE_CORRUPT               1392L

//
// MessageId: ERROR_DISK_CORRUPT
//
// MessageText:
//
// The disk structure is corrupted and unreadable.
//
#define ERROR_DISK_CORRUPT               1393L

//
// MessageId: ERROR_NO_USER_SESSION_KEY
//
// MessageText:
//
// There is no user session key for the specified logon session.
//
#define ERROR_NO_USER_SESSION_KEY        1394L

//
// MessageId: ERROR_LICENSE_QUOTA_EXCEEDED
//
// MessageText:
//
// The service being accessed is licensed for a particular number of connections.
// No more connections can be made to the service at this time because there are already as many connections as the service can accept.
//
#define ERROR_LICENSE_QUOTA_EXCEEDED     1395L

//
// MessageId: ERROR_WRONG_TARGET_NAME
//
// MessageText:
//
// Logon Failure: The target account name is incorrect.
//
#define ERROR_WRONG_TARGET_NAME          1396L

//
// MessageId: ERROR_MUTUAL_AUTH_FAILED
//
// MessageText:
//
// Mutual Authentication failed. The server's password is out of date at the domain controller.
//
#define ERROR_MUTUAL_AUTH_FAILED         1397L

//
// MessageId: ERROR_TIME_SKEW
//
// MessageText:
//
// There is a time and/or date difference between the client and server.
//
#define ERROR_TIME_SKEW                  1398L

//
// MessageId: ERROR_CURRENT_DOMAIN_NOT_ALLOWED
//
// MessageText:
//
// This operation cannot be performed on the current domain.
//
#define ERROR_CURRENT_DOMAIN_NOT_ALLOWED 1399L


///////////////////////////////////////////////////
//                                               //
//              WinUser Error codes              //
//                                               //
//                 1400 to 1499                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_INVALID_WINDOW_HANDLE
//
// MessageText:
//
// Invalid window handle.
//
#define ERROR_INVALID_WINDOW_HANDLE      1400L

//
// MessageId: ERROR_INVALID_MENU_HANDLE
//
// MessageText:
//
// Invalid menu handle.
//
#define ERROR_INVALID_MENU_HANDLE        1401L

//
// MessageId: ERROR_INVALID_CURSOR_HANDLE
//
// MessageText:
//
// Invalid cursor handle.
//
#define ERROR_INVALID_CURSOR_HANDLE      1402L

//
// MessageId: ERROR_INVALID_ACCEL_HANDLE
//
// MessageText:
//
// Invalid accelerator table handle.
//
#define ERROR_INVALID_ACCEL_HANDLE       1403L

//
// MessageId: ERROR_INVALID_HOOK_HANDLE
//
// MessageText:
//
// Invalid hook handle.
//
#define ERROR_INVALID_HOOK_HANDLE        1404L

//
// MessageId: ERROR_INVALID_DWP_HANDLE
//
// MessageText:
//
// Invalid handle to a multiple-window position structure.
//
#define ERROR_INVALID_DWP_HANDLE         1405L

//
// MessageId: ERROR_TLW_WITH_WSCHILD
//
// MessageText:
//
// Cannot create a top-level child window.
//
#define ERROR_TLW_WITH_WSCHILD           1406L

//
// MessageId: ERROR_CANNOT_FIND_WND_CLASS
//
// MessageText:
//
// Cannot find window class.
//
#define ERROR_CANNOT_FIND_WND_CLASS      1407L

//
// MessageId: ERROR_WINDOW_OF_OTHER_THREAD
//
// MessageText:
//
// Invalid window; it belongs to other thread.
//
#define ERROR_WINDOW_OF_OTHER_THREAD     1408L

//
// MessageId: ERROR_HOTKEY_ALREADY_REGISTERED
//
// MessageText:
//
// Hot key is already registered.
//
#define ERROR_HOTKEY_ALREADY_REGISTERED  1409L

//
// MessageId: ERROR_CLASS_ALREADY_EXISTS
//
// MessageText:
//
// Class already exists.
//
#define ERROR_CLASS_ALREADY_EXISTS       1410L

//
// MessageId: ERROR_CLASS_DOES_NOT_EXIST
//
// MessageText:
//
// Class does not exist.
//
#define ERROR_CLASS_DOES_NOT_EXIST       1411L

//
// MessageId: ERROR_CLASS_HAS_WINDOWS
//
// MessageText:
//
// Class still has open windows.
//
#define ERROR_CLASS_HAS_WINDOWS          1412L

//
// MessageId: ERROR_INVALID_INDEX
//
// MessageText:
//
// Invalid index.
//
#define ERROR_INVALID_INDEX              1413L

//
// MessageId: ERROR_INVALID_ICON_HANDLE
//
// MessageText:
//
// Invalid icon handle.
//
#define ERROR_INVALID_ICON_HANDLE        1414L

//
// MessageId: ERROR_PRIVATE_DIALOG_INDEX
//
// MessageText:
//
// Using private DIALOG window words.
//
#define ERROR_PRIVATE_DIALOG_INDEX       1415L

//
// MessageId: ERROR_LISTBOX_ID_NOT_FOUND
//
// MessageText:
//
// The list box identifier was not found.
//
#define ERROR_LISTBOX_ID_NOT_FOUND       1416L

//
// MessageId: ERROR_NO_WILDCARD_CHARACTERS
//
// MessageText:
//
// No wildcards were found.
//
#define ERROR_NO_WILDCARD_CHARACTERS     1417L

//
// MessageId: ERROR_CLIPBOARD_NOT_OPEN
//
// MessageText:
//
// Thread does not have a clipboard open.
//
#define ERROR_CLIPBOARD_NOT_OPEN         1418L

//
// MessageId: ERROR_HOTKEY_NOT_REGISTERED
//
// MessageText:
//
// Hot key is not registered.
//
#define ERROR_HOTKEY_NOT_REGISTERED      1419L

//
// MessageId: ERROR_WINDOW_NOT_DIALOG
//
// MessageText:
//
// The window is not a valid dialog window.
//
#define ERROR_WINDOW_NOT_DIALOG          1420L

//
// MessageId: ERROR_CONTROL_ID_NOT_FOUND
//
// MessageText:
//
// Control ID not found.
//
#define ERROR_CONTROL_ID_NOT_FOUND       1421L

//
// MessageId: ERROR_INVALID_COMBOBOX_MESSAGE
//
// MessageText:
//
// Invalid message for a combo box because it does not have an edit control.
//
#define ERROR_INVALID_COMBOBOX_MESSAGE   1422L

//
// MessageId: ERROR_WINDOW_NOT_COMBOBOX
//
// MessageText:
//
// The window is not a combo box.
//
#define ERROR_WINDOW_NOT_COMBOBOX        1423L

//
// MessageId: ERROR_INVALID_EDIT_HEIGHT
//
// MessageText:
//
// Height must be less than 256.
//
#define ERROR_INVALID_EDIT_HEIGHT        1424L

//
// MessageId: ERROR_DC_NOT_FOUND
//
// MessageText:
//
// Invalid device context (DC) handle.
//
#define ERROR_DC_NOT_FOUND               1425L

//
// MessageId: ERROR_INVALID_HOOK_FILTER
//
// MessageText:
//
// Invalid hook procedure type.
//
#define ERROR_INVALID_HOOK_FILTER        1426L

//
// MessageId: ERROR_INVALID_FILTER_PROC
//
// MessageText:
//
// Invalid hook procedure.
//
#define ERROR_INVALID_FILTER_PROC        1427L

//
// MessageId: ERROR_HOOK_NEEDS_HMOD
//
// MessageText:
//
// Cannot set nonlocal hook without a module handle.
//
#define ERROR_HOOK_NEEDS_HMOD            1428L

//
// MessageId: ERROR_GLOBAL_ONLY_HOOK
//
// MessageText:
//
// This hook procedure can only be set globally.
//
#define ERROR_GLOBAL_ONLY_HOOK           1429L

//
// MessageId: ERROR_JOURNAL_HOOK_SET
//
// MessageText:
//
// The journal hook procedure is already installed.
//
#define ERROR_JOURNAL_HOOK_SET           1430L

//
// MessageId: ERROR_HOOK_NOT_INSTALLED
//
// MessageText:
//
// The hook procedure is not installed.
//
#define ERROR_HOOK_NOT_INSTALLED         1431L

//
// MessageId: ERROR_INVALID_LB_MESSAGE
//
// MessageText:
//
// Invalid message for single-selection list box.
//
#define ERROR_INVALID_LB_MESSAGE         1432L

//
// MessageId: ERROR_SETCOUNT_ON_BAD_LB
//
// MessageText:
//
// LB_SETCOUNT sent to non-lazy list box.
//
#define ERROR_SETCOUNT_ON_BAD_LB         1433L

//
// MessageId: ERROR_LB_WITHOUT_TABSTOPS
//
// MessageText:
//
// This list box does not support tab stops.
//
#define ERROR_LB_WITHOUT_TABSTOPS        1434L

//
// MessageId: ERROR_DESTROY_OBJECT_OF_OTHER_THREAD
//
// MessageText:
//
// Cannot destroy object created by another thread.
//
#define ERROR_DESTROY_OBJECT_OF_OTHER_THREAD 1435L

//
// MessageId: ERROR_CHILD_WINDOW_MENU
//
// MessageText:
//
// Child windows cannot have menus.
//
#define ERROR_CHILD_WINDOW_MENU          1436L

//
// MessageId: ERROR_NO_SYSTEM_MENU
//
// MessageText:
//
// The window does not have a system menu.
//
#define ERROR_NO_SYSTEM_MENU             1437L

//
// MessageId: ERROR_INVALID_MSGBOX_STYLE
//
// MessageText:
//
// Invalid message box style.
//
#define ERROR_INVALID_MSGBOX_STYLE       1438L

//
// MessageId: ERROR_INVALID_SPI_VALUE
//
// MessageText:
//
// Invalid system-wide (SPI_*) parameter.
//
#define ERROR_INVALID_SPI_VALUE          1439L

//
// MessageId: ERROR_SCREEN_ALREADY_LOCKED
//
// MessageText:
//
// Screen already locked.
//
#define ERROR_SCREEN_ALREADY_LOCKED      1440L

//
// MessageId: ERROR_HWNDS_HAVE_DIFF_PARENT
//
// MessageText:
//
// All handles to windows in a multiple-window position structure must have the same parent.
//
#define ERROR_HWNDS_HAVE_DIFF_PARENT     1441L

//
// MessageId: ERROR_NOT_CHILD_WINDOW
//
// MessageText:
//
// The window is not a child window.
//
#define ERROR_NOT_CHILD_WINDOW           1442L

//
// MessageId: ERROR_INVALID_GW_COMMAND
//
// MessageText:
//
// Invalid GW_* command.
//
#define ERROR_INVALID_GW_COMMAND         1443L

//
// MessageId: ERROR_INVALID_THREAD_ID
//
// MessageText:
//
// Invalid thread identifier.
//
#define ERROR_INVALID_THREAD_ID          1444L

//
// MessageId: ERROR_NON_MDICHILD_WINDOW
//
// MessageText:
//
// Cannot process a message from a window that is not a multiple document interface (MDI) window.
//
#define ERROR_NON_MDICHILD_WINDOW        1445L

//
// MessageId: ERROR_POPUP_ALREADY_ACTIVE
//
// MessageText:
//
// Popup menu already active.
//
#define ERROR_POPUP_ALREADY_ACTIVE       1446L

//
// MessageId: ERROR_NO_SCROLLBARS
//
// MessageText:
//
// The window does not have scroll bars.
//
#define ERROR_NO_SCROLLBARS              1447L

//
// MessageId: ERROR_INVALID_SCROLLBAR_RANGE
//
// MessageText:
//
// Scroll bar range cannot be greater than MAXLONG.
//
#define ERROR_INVALID_SCROLLBAR_RANGE    1448L

//
// MessageId: ERROR_INVALID_SHOWWIN_COMMAND
//
// MessageText:
//
// Cannot show or remove the window in the way specified.
//
#define ERROR_INVALID_SHOWWIN_COMMAND    1449L

//
// MessageId: ERROR_NO_SYSTEM_RESOURCES
//
// MessageText:
//
// Insufficient system resources exist to complete the requested service.
//
#define ERROR_NO_SYSTEM_RESOURCES        1450L

//
// MessageId: ERROR_NONPAGED_SYSTEM_RESOURCES
//
// MessageText:
//
// Insufficient system resources exist to complete the requested service.
//
#define ERROR_NONPAGED_SYSTEM_RESOURCES  1451L

//
// MessageId: ERROR_PAGED_SYSTEM_RESOURCES
//
// MessageText:
//
// Insufficient system resources exist to complete the requested service.
//
#define ERROR_PAGED_SYSTEM_RESOURCES     1452L

//
// MessageId: ERROR_WORKING_SET_QUOTA
//
// MessageText:
//
// Insufficient quota to complete the requested service.
//
#define ERROR_WORKING_SET_QUOTA          1453L

//
// MessageId: ERROR_PAGEFILE_QUOTA
//
// MessageText:
//
// Insufficient quota to complete the requested service.
//
#define ERROR_PAGEFILE_QUOTA             1454L

//
// MessageId: ERROR_COMMITMENT_LIMIT
//
// MessageText:
//
// The paging file is too small for this operation to complete.
//
#define ERROR_COMMITMENT_LIMIT           1455L

//
// MessageId: ERROR_MENU_ITEM_NOT_FOUND
//
// MessageText:
//
// A menu item was not found.
//
#define ERROR_MENU_ITEM_NOT_FOUND        1456L

//
// MessageId: ERROR_INVALID_KEYBOARD_HANDLE
//
// MessageText:
//
// Invalid keyboard layout handle.
//
#define ERROR_INVALID_KEYBOARD_HANDLE    1457L

//
// MessageId: ERROR_HOOK_TYPE_NOT_ALLOWED
//
// MessageText:
//
// Hook type not allowed.
//
#define ERROR_HOOK_TYPE_NOT_ALLOWED      1458L

//
// MessageId: ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION
//
// MessageText:
//
// This operation requires an interactive window station.
//
#define ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION 1459L

//
// MessageId: ERROR_TIMEOUT
//
// MessageText:
//
// This operation returned because the timeout period expired.
//
#define ERROR_TIMEOUT                    1460L

//
// MessageId: ERROR_INVALID_MONITOR_HANDLE
//
// MessageText:
//
// Invalid monitor handle.
//
#define ERROR_INVALID_MONITOR_HANDLE     1461L

//
// MessageId: ERROR_INCORRECT_SIZE
//
// MessageText:
//
//  Incorrect size argument.
//
#define ERROR_INCORRECT_SIZE             1462L

//
// MessageId: ERROR_SYMLINK_CLASS_DISABLED
//
// MessageText:
//
// The symbolic link cannot be followed because its type is disabled.
//
#define ERROR_SYMLINK_CLASS_DISABLED     1463L

//
// MessageId: ERROR_SYMLINK_NOT_SUPPORTED
//
// MessageText:
//
// This application does not support the current operation on symbolic links.
//
#define ERROR_SYMLINK_NOT_SUPPORTED      1464L

//
// MessageId: ERROR_XML_PARSE_ERROR
//
// MessageText:
//
// Windows was unable to parse the requested XML data.
//
#define ERROR_XML_PARSE_ERROR            1465L

//
// MessageId: ERROR_XMLDSIG_ERROR
//
// MessageText:
//
// An error was encountered while processing an XML digital signature.
//
#define ERROR_XMLDSIG_ERROR              1466L

//
// MessageId: ERROR_RESTART_APPLICATION
//
// MessageText:
//
// This application must be restarted.
//
#define ERROR_RESTART_APPLICATION        1467L

//
// MessageId: ERROR_WRONG_COMPARTMENT
//
// MessageText:
//
// The caller made the connection request in the wrong routing compartment.
//
#define ERROR_WRONG_COMPARTMENT          1468L

//
// MessageId: ERROR_AUTHIP_FAILURE
//
// MessageText:
//
// There was an AuthIP failure when attempting to connect to the remote host.
//
#define ERROR_AUTHIP_FAILURE             1469L


///////////////////////////////////////////////////
//                                               //
//             EventLog Error codes              //
//                                               //
//                 1500 to 1549                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_EVENTLOG_FILE_CORRUPT
//
// MessageText:
//
// The event log file is corrupted.
//
#define ERROR_EVENTLOG_FILE_CORRUPT      1500L

//
// MessageId: ERROR_EVENTLOG_CANT_START
//
// MessageText:
//
// No event log file could be opened, so the event logging service did not start.
//
#define ERROR_EVENTLOG_CANT_START        1501L

//
// MessageId: ERROR_LOG_FILE_FULL
//
// MessageText:
//
// The event log file is full.
//
#define ERROR_LOG_FILE_FULL              1502L

//
// MessageId: ERROR_EVENTLOG_FILE_CHANGED
//
// MessageText:
//
// The event log file has changed between read operations.
//
#define ERROR_EVENTLOG_FILE_CHANGED      1503L


///////////////////////////////////////////////////
//                                               //
//            Class Scheduler Error codes        //
//                                               //
//                 1550 to 1599                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_INVALID_TASK_NAME
//
// MessageText:
//
// The specified task name is invalid.
//
#define ERROR_INVALID_TASK_NAME          1550L

//
// MessageId: ERROR_INVALID_TASK_INDEX
//
// MessageText:
//
// The specified task index is invalid.
//
#define ERROR_INVALID_TASK_INDEX         1551L

//
// MessageId: ERROR_THREAD_ALREADY_IN_TASK
//
// MessageText:
//
// The specified thread is already joining a task.
//
#define ERROR_THREAD_ALREADY_IN_TASK     1552L


///////////////////////////////////////////////////
//                                               //
//                MSI Error codes                //
//                                               //
//                 1600 to 1699                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_INSTALL_SERVICE_FAILURE
//
// MessageText:
//
// The Windows Installer Service could not be accessed. This can occur if the Windows Installer is not correctly installed. Contact your support personnel for assistance.
//
#define ERROR_INSTALL_SERVICE_FAILURE    1601L

//
// MessageId: ERROR_INSTALL_USEREXIT
//
// MessageText:
//
// User cancelled installation.
//
#define ERROR_INSTALL_USEREXIT           1602L

//
// MessageId: ERROR_INSTALL_FAILURE
//
// MessageText:
//
// Fatal error during installation.
//
#define ERROR_INSTALL_FAILURE            1603L

//
// MessageId: ERROR_INSTALL_SUSPEND
//
// MessageText:
//
// Installation suspended, incomplete.
//
#define ERROR_INSTALL_SUSPEND            1604L

//
// MessageId: ERROR_UNKNOWN_PRODUCT
//
// MessageText:
//
// This action is only valid for products that are currently installed.
//
#define ERROR_UNKNOWN_PRODUCT            1605L

//
// MessageId: ERROR_UNKNOWN_FEATURE
//
// MessageText:
//
// Feature ID not registered.
//
#define ERROR_UNKNOWN_FEATURE            1606L

//
// MessageId: ERROR_UNKNOWN_COMPONENT
//
// MessageText:
//
// Component ID not registered.
//
#define ERROR_UNKNOWN_COMPONENT          1607L

//
// MessageId: ERROR_UNKNOWN_PROPERTY
//
// MessageText:
//
// Unknown property.
//
#define ERROR_UNKNOWN_PROPERTY           1608L

//
// MessageId: ERROR_INVALID_HANDLE_STATE
//
// MessageText:
//
// Handle is in an invalid state.
//
#define ERROR_INVALID_HANDLE_STATE       1609L

//
// MessageId: ERROR_BAD_CONFIGURATION
//
// MessageText:
//
// The configuration data for this product is corrupt. Contact your support personnel.
//
#define ERROR_BAD_CONFIGURATION          1610L

//
// MessageId: ERROR_INDEX_ABSENT
//
// MessageText:
//
// Component qualifier not present.
//
#define ERROR_INDEX_ABSENT               1611L

//
// MessageId: ERROR_INSTALL_SOURCE_ABSENT
//
// MessageText:
//
// The installation source for this product is not available. Verify that the source exists and that you can access it.
//
#define ERROR_INSTALL_SOURCE_ABSENT      1612L

//
// MessageId: ERROR_INSTALL_PACKAGE_VERSION
//
// MessageText:
//
// This installation package cannot be installed by the Windows Installer service. You must install a Windows service pack that contains a newer version of the Windows Installer service.
//
#define ERROR_INSTALL_PACKAGE_VERSION    1613L

//
// MessageId: ERROR_PRODUCT_UNINSTALLED
//
// MessageText:
//
// Product is uninstalled.
//
#define ERROR_PRODUCT_UNINSTALLED        1614L

//
// MessageId: ERROR_BAD_QUERY_SYNTAX
//
// MessageText:
//
// SQL query syntax invalid or unsupported.
//
#define ERROR_BAD_QUERY_SYNTAX           1615L

//
// MessageId: ERROR_INVALID_FIELD
//
// MessageText:
//
// Record field does not exist.
//
#define ERROR_INVALID_FIELD              1616L

//
// MessageId: ERROR_DEVICE_REMOVED
//
// MessageText:
//
// The device has been removed.
//
#define ERROR_DEVICE_REMOVED             1617L

//
// MessageId: ERROR_INSTALL_ALREADY_RUNNING
//
// MessageText:
//
// Another installation is already in progress. Complete that installation before proceeding with this install.
//
#define ERROR_INSTALL_ALREADY_RUNNING    1618L

//
// MessageId: ERROR_INSTALL_PACKAGE_OPEN_FAILED
//
// MessageText:
//
// This installation package could not be opened. Verify that the package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer package.
//
#define ERROR_INSTALL_PACKAGE_OPEN_FAILED 1619L

//
// MessageId: ERROR_INSTALL_PACKAGE_INVALID
//
// MessageText:
//
// This installation package could not be opened. Contact the application vendor to verify that this is a valid Windows Installer package.
//
#define ERROR_INSTALL_PACKAGE_INVALID    1620L

//
// MessageId: ERROR_INSTALL_UI_FAILURE
//
// MessageText:
//
// There was an error starting the Windows Installer service user interface. Contact your support personnel.
//
#define ERROR_INSTALL_UI_FAILURE         1621L

//
// MessageId: ERROR_INSTALL_LOG_FAILURE
//
// MessageText:
//
// Error opening installation log file. Verify that the specified log file location exists and that you can write to it.
//
#define ERROR_INSTALL_LOG_FAILURE        1622L

//
// MessageId: ERROR_INSTALL_LANGUAGE_UNSUPPORTED
//
// MessageText:
//
// The language of this installation package is not supported by your system.
//
#define ERROR_INSTALL_LANGUAGE_UNSUPPORTED 1623L

//
// MessageId: ERROR_INSTALL_TRANSFORM_FAILURE
//
// MessageText:
//
// Error applying transforms. Verify that the specified transform paths are valid.
//
#define ERROR_INSTALL_TRANSFORM_FAILURE  1624L

//
// MessageId: ERROR_INSTALL_PACKAGE_REJECTED
//
// MessageText:
//
// This installation is forbidden by system policy. Contact your system administrator.
//
#define ERROR_INSTALL_PACKAGE_REJECTED   1625L

//
// MessageId: ERROR_FUNCTION_NOT_CALLED
//
// MessageText:
//
// Function could not be executed.
//
#define ERROR_FUNCTION_NOT_CALLED        1626L

//
// MessageId: ERROR_FUNCTION_FAILED
//
// MessageText:
//
// Function failed during execution.
//
#define ERROR_FUNCTION_FAILED            1627L

//
// MessageId: ERROR_INVALID_TABLE
//
// MessageText:
//
// Invalid or unknown table specified.
//
#define ERROR_INVALID_TABLE              1628L

//
// MessageId: ERROR_DATATYPE_MISMATCH
//
// MessageText:
//
// Data supplied is of wrong type.
//
#define ERROR_DATATYPE_MISMATCH          1629L

//
// MessageId: ERROR_UNSUPPORTED_TYPE
//
// MessageText:
//
// Data of this type is not supported.
//
#define ERROR_UNSUPPORTED_TYPE           1630L

//
// MessageId: ERROR_CREATE_FAILED
//
// MessageText:
//
// The Windows Installer service failed to start. Contact your support personnel.
//
#define ERROR_CREATE_FAILED              1631L

//
// MessageId: ERROR_INSTALL_TEMP_UNWRITABLE
//
// MessageText:
//
// The Temp folder is on a drive that is full or is inaccessible. Free up space on the drive or verify that you have write permission on the Temp folder.
//
#define ERROR_INSTALL_TEMP_UNWRITABLE    1632L

//
// MessageId: ERROR_INSTALL_PLATFORM_UNSUPPORTED
//
// MessageText:
//
// This installation package is not supported by this processor type. Contact your product vendor.
//
#define ERROR_INSTALL_PLATFORM_UNSUPPORTED 1633L

//
// MessageId: ERROR_INSTALL_NOTUSED
//
// MessageText:
//
// Component not used on this computer.
//
#define ERROR_INSTALL_NOTUSED            1634L

//
// MessageId: ERROR_PATCH_PACKAGE_OPEN_FAILED
//
// MessageText:
//
// This update package could not be opened. Verify that the update package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer update package.
//
#define ERROR_PATCH_PACKAGE_OPEN_FAILED  1635L

//
// MessageId: ERROR_PATCH_PACKAGE_INVALID
//
// MessageText:
//
// This update package could not be opened. Contact the application vendor to verify that this is a valid Windows Installer update package.
//
#define ERROR_PATCH_PACKAGE_INVALID      1636L

//
// MessageId: ERROR_PATCH_PACKAGE_UNSUPPORTED
//
// MessageText:
//
// This update package cannot be processed by the Windows Installer service. You must install a Windows service pack that contains a newer version of the Windows Installer service.
//
#define ERROR_PATCH_PACKAGE_UNSUPPORTED  1637L

//
// MessageId: ERROR_PRODUCT_VERSION
//
// MessageText:
//
// Another version of this product is already installed. Installation of this version cannot continue. To configure or remove the existing version of this product, use Add/Remove Programs on the Control Panel.
//
#define ERROR_PRODUCT_VERSION            1638L

//
// MessageId: ERROR_INVALID_COMMAND_LINE
//
// MessageText:
//
// Invalid command line argument. Consult the Windows Installer SDK for detailed command line help.
//
#define ERROR_INVALID_COMMAND_LINE       1639L

//
// MessageId: ERROR_INSTALL_REMOTE_DISALLOWED
//
// MessageText:
//
// Only administrators have permission to add, remove, or configure server software during a Terminal services remote session. If you want to install or configure software on the server, contact your network administrator.
//
#define ERROR_INSTALL_REMOTE_DISALLOWED  1640L

//
// MessageId: ERROR_SUCCESS_REBOOT_INITIATED
//
// MessageText:
//
// The requested operation completed successfully. The system will be restarted so the changes can take effect.
//
#define ERROR_SUCCESS_REBOOT_INITIATED   1641L

//
// MessageId: ERROR_PATCH_TARGET_NOT_FOUND
//
// MessageText:
//
// The upgrade cannot be installed by the Windows Installer service because the program to be upgraded may be missing, or the upgrade may update a different version of the program. Verify that the program to be upgraded exists on your computer and that you have the correct upgrade.
//
#define ERROR_PATCH_TARGET_NOT_FOUND     1642L

//
// MessageId: ERROR_PATCH_PACKAGE_REJECTED
//
// MessageText:
//
// The update package is not permitted by software restriction policy.
//
#define ERROR_PATCH_PACKAGE_REJECTED     1643L

//
// MessageId: ERROR_INSTALL_TRANSFORM_REJECTED
//
// MessageText:
//
// One or more customizations are not permitted by software restriction policy.
//
#define ERROR_INSTALL_TRANSFORM_REJECTED 1644L

//
// MessageId: ERROR_INSTALL_REMOTE_PROHIBITED
//
// MessageText:
//
// The Windows Installer does not permit installation from a Remote Desktop Connection.
//
#define ERROR_INSTALL_REMOTE_PROHIBITED  1645L

//
// MessageId: ERROR_PATCH_REMOVAL_UNSUPPORTED
//
// MessageText:
//
// Uninstallation of the update package is not supported.
//
#define ERROR_PATCH_REMOVAL_UNSUPPORTED  1646L

//
// MessageId: ERROR_UNKNOWN_PATCH
//
// MessageText:
//
// The update is not applied to this product.
//
#define ERROR_UNKNOWN_PATCH              1647L

//
// MessageId: ERROR_PATCH_NO_SEQUENCE
//
// MessageText:
//
// No valid sequence could be found for the set of updates.
//
#define ERROR_PATCH_NO_SEQUENCE          1648L

//
// MessageId: ERROR_PATCH_REMOVAL_DISALLOWED
//
// MessageText:
//
// Update removal was disallowed by policy.
//
#define ERROR_PATCH_REMOVAL_DISALLOWED   1649L

//
// MessageId: ERROR_INVALID_PATCH_XML
//
// MessageText:
//
// The XML update data is invalid.
//
#define ERROR_INVALID_PATCH_XML          1650L

//
// MessageId: ERROR_PATCH_MANAGED_ADVERTISED_PRODUCT
//
// MessageText:
//
// Windows Installer does not permit updating of managed advertised products. At least one feature of the product must be installed before applying the update.
//
#define ERROR_PATCH_MANAGED_ADVERTISED_PRODUCT 1651L

//
// MessageId: ERROR_INSTALL_SERVICE_SAFEBOOT
//
// MessageText:
//
// The Windows Installer service is not accessible in Safe Mode. Please try again when your computer is not in Safe Mode or you can use System Restore to return your machine to a previous good state.
//
#define ERROR_INSTALL_SERVICE_SAFEBOOT   1652L


///////////////////////////////////////////////////
//                                               //
//               RPC Error codes                 //
//                                               //
//                 1700 to 1999                  //
///////////////////////////////////////////////////

//
// MessageId: RPC_S_INVALID_STRING_BINDING
//
// MessageText:
//
// The string binding is invalid.
//
#define RPC_S_INVALID_STRING_BINDING     1700L

//
// MessageId: RPC_S_WRONG_KIND_OF_BINDING
//
// MessageText:
//
// The binding handle is not the correct type.
//
#define RPC_S_WRONG_KIND_OF_BINDING      1701L

//
// MessageId: RPC_S_INVALID_BINDING
//
// MessageText:
//
// The binding handle is invalid.
//
#define RPC_S_INVALID_BINDING            1702L

//
// MessageId: RPC_S_PROTSEQ_NOT_SUPPORTED
//
// MessageText:
//
// The RPC protocol sequence is not supported.
//
#define RPC_S_PROTSEQ_NOT_SUPPORTED      1703L

//
// MessageId: RPC_S_INVALID_RPC_PROTSEQ
//
// MessageText:
//
// The RPC protocol sequence is invalid.
//
#define RPC_S_INVALID_RPC_PROTSEQ        1704L

//
// MessageId: RPC_S_INVALID_STRING_UUID
//
// MessageText:
//
// The string universal unique identifier (UUID) is invalid.
//
#define RPC_S_INVALID_STRING_UUID        1705L

//
// MessageId: RPC_S_INVALID_ENDPOINT_FORMAT
//
// MessageText:
//
// The endpoint format is invalid.
//
#define RPC_S_INVALID_ENDPOINT_FORMAT    1706L

//
// MessageId: RPC_S_INVALID_NET_ADDR
//
// MessageText:
//
// The network address is invalid.
//
#define RPC_S_INVALID_NET_ADDR           1707L

//
// MessageId: RPC_S_NO_ENDPOINT_FOUND
//
// MessageText:
//
// No endpoint was found.
//
#define RPC_S_NO_ENDPOINT_FOUND          1708L

//
// MessageId: RPC_S_INVALID_TIMEOUT
//
// MessageText:
//
// The timeout value is invalid.
//
#define RPC_S_INVALID_TIMEOUT            1709L

//
// MessageId: RPC_S_OBJECT_NOT_FOUND
//
// MessageText:
//
// The object universal unique identifier (UUID) was not found.
//
#define RPC_S_OBJECT_NOT_FOUND           1710L

//
// MessageId: RPC_S_ALREADY_REGISTERED
//
// MessageText:
//
// The object universal unique identifier (UUID) has already been registered.
//
#define RPC_S_ALREADY_REGISTERED         1711L

//
// MessageId: RPC_S_TYPE_ALREADY_REGISTERED
//
// MessageText:
//
// The type universal unique identifier (UUID) has already been registered.
//
#define RPC_S_TYPE_ALREADY_REGISTERED    1712L

//
// MessageId: RPC_S_ALREADY_LISTENING
//
// MessageText:
//
// The RPC server is already listening.
//
#define RPC_S_ALREADY_LISTENING          1713L

//
// MessageId: RPC_S_NO_PROTSEQS_REGISTERED
//
// MessageText:
//
// No protocol sequences have been registered.
//
#define RPC_S_NO_PROTSEQS_REGISTERED     1714L

//
// MessageId: RPC_S_NOT_LISTENING
//
// MessageText:
//
// The RPC server is not listening.
//
#define RPC_S_NOT_LISTENING              1715L

//
// MessageId: RPC_S_UNKNOWN_MGR_TYPE
//
// MessageText:
//
// The manager type is unknown.
//
#define RPC_S_UNKNOWN_MGR_TYPE           1716L

//
// MessageId: RPC_S_UNKNOWN_IF
//
// MessageText:
//
// The interface is unknown.
//
#define RPC_S_UNKNOWN_IF                 1717L

//
// MessageId: RPC_S_NO_BINDINGS
//
// MessageText:
//
// There are no bindings.
//
#define RPC_S_NO_BINDINGS                1718L

//
// MessageId: RPC_S_NO_PROTSEQS
//
// MessageText:
//
// There are no protocol sequences.
//
#define RPC_S_NO_PROTSEQS                1719L

//
// MessageId: RPC_S_CANT_CREATE_ENDPOINT
//
// MessageText:
//
// The endpoint cannot be created.
//
#define RPC_S_CANT_CREATE_ENDPOINT       1720L

//
// MessageId: RPC_S_OUT_OF_RESOURCES
//
// MessageText:
//
// Not enough resources are available to complete this operation.
//
#define RPC_S_OUT_OF_RESOURCES           1721L

//
// MessageId: RPC_S_SERVER_UNAVAILABLE
//
// MessageText:
//
// The RPC server is unavailable.
//
#define RPC_S_SERVER_UNAVAILABLE         1722L

//
// MessageId: RPC_S_SERVER_TOO_BUSY
//
// MessageText:
//
// The RPC server is too busy to complete this operation.
//
#define RPC_S_SERVER_TOO_BUSY            1723L

//
// MessageId: RPC_S_INVALID_NETWORK_OPTIONS
//
// MessageText:
//
// The network options are invalid.
//
#define RPC_S_INVALID_NETWORK_OPTIONS    1724L

//
// MessageId: RPC_S_NO_CALL_ACTIVE
//
// MessageText:
//
// There are no remote procedure calls active on this thread.
//
#define RPC_S_NO_CALL_ACTIVE             1725L

//
// MessageId: RPC_S_CALL_FAILED
//
// MessageText:
//
// The remote procedure call failed.
//
#define RPC_S_CALL_FAILED                1726L

//
// MessageId: RPC_S_CALL_FAILED_DNE
//
// MessageText:
//
// The remote procedure call failed and did not execute.
//
#define RPC_S_CALL_FAILED_DNE            1727L

//
// MessageId: RPC_S_PROTOCOL_ERROR
//
// MessageText:
//
// A remote procedure call (RPC) protocol error occurred.
//
#define RPC_S_PROTOCOL_ERROR             1728L

//
// MessageId: RPC_S_PROXY_ACCESS_DENIED
//
// MessageText:
//
// Access to the HTTP proxy is denied.
//
#define RPC_S_PROXY_ACCESS_DENIED        1729L

//
// MessageId: RPC_S_UNSUPPORTED_TRANS_SYN
//
// MessageText:
//
// The transfer syntax is not supported by the RPC server.
//
#define RPC_S_UNSUPPORTED_TRANS_SYN      1730L

//
// MessageId: RPC_S_UNSUPPORTED_TYPE
//
// MessageText:
//
// The universal unique identifier (UUID) type is not supported.
//
#define RPC_S_UNSUPPORTED_TYPE           1732L

//
// MessageId: RPC_S_INVALID_TAG
//
// MessageText:
//
// The tag is invalid.
//
#define RPC_S_INVALID_TAG                1733L

//
// MessageId: RPC_S_INVALID_BOUND
//
// MessageText:
//
// The array bounds are invalid.
//
#define RPC_S_INVALID_BOUND              1734L

//
// MessageId: RPC_S_NO_ENTRY_NAME
//
// MessageText:
//
// The binding does not contain an entry name.
//
#define RPC_S_NO_ENTRY_NAME              1735L

//
// MessageId: RPC_S_INVALID_NAME_SYNTAX
//
// MessageText:
//
// The name syntax is invalid.
//
#define RPC_S_INVALID_NAME_SYNTAX        1736L

//
// MessageId: RPC_S_UNSUPPORTED_NAME_SYNTAX
//
// MessageText:
//
// The name syntax is not supported.
//
#define RPC_S_UNSUPPORTED_NAME_SYNTAX    1737L

//
// MessageId: RPC_S_UUID_NO_ADDRESS
//
// MessageText:
//
// No network address is available to use to construct a universal unique identifier (UUID).
//
#define RPC_S_UUID_NO_ADDRESS            1739L

//
// MessageId: RPC_S_DUPLICATE_ENDPOINT
//
// MessageText:
//
// The endpoint is a duplicate.
//
#define RPC_S_DUPLICATE_ENDPOINT         1740L

//
// MessageId: RPC_S_UNKNOWN_AUTHN_TYPE
//
// MessageText:
//
// The authentication type is unknown.
//
#define RPC_S_UNKNOWN_AUTHN_TYPE         1741L

//
// MessageId: RPC_S_MAX_CALLS_TOO_SMALL
//
// MessageText:
//
// The maximum number of calls is too small.
//
#define RPC_S_MAX_CALLS_TOO_SMALL        1742L

//
// MessageId: RPC_S_STRING_TOO_LONG
//
// MessageText:
//
// The string is too long.
//
#define RPC_S_STRING_TOO_LONG            1743L

//
// MessageId: RPC_S_PROTSEQ_NOT_FOUND
//
// MessageText:
//
// The RPC protocol sequence was not found.
//
#define RPC_S_PROTSEQ_NOT_FOUND          1744L

//
// MessageId: RPC_S_PROCNUM_OUT_OF_RANGE
//
// MessageText:
//
// The procedure number is out of range.
//
#define RPC_S_PROCNUM_OUT_OF_RANGE       1745L

//
// MessageId: RPC_S_BINDING_HAS_NO_AUTH
//
// MessageText:
//
// The binding does not contain any authentication information.
//
#define RPC_S_BINDING_HAS_NO_AUTH        1746L

//
// MessageId: RPC_S_UNKNOWN_AUTHN_SERVICE
//
// MessageText:
//
// The authentication service is unknown.
//
#define RPC_S_UNKNOWN_AUTHN_SERVICE      1747L

//
// MessageId: RPC_S_UNKNOWN_AUTHN_LEVEL
//
// MessageText:
//
// The authentication level is unknown.
//
#define RPC_S_UNKNOWN_AUTHN_LEVEL        1748L

//
// MessageId: RPC_S_INVALID_AUTH_IDENTITY
//
// MessageText:
//
// The security context is invalid.
//
#define RPC_S_INVALID_AUTH_IDENTITY      1749L

//
// MessageId: RPC_S_UNKNOWN_AUTHZ_SERVICE
//
// MessageText:
//
// The authorization service is unknown.
//
#define RPC_S_UNKNOWN_AUTHZ_SERVICE      1750L

//
// MessageId: EPT_S_INVALID_ENTRY
//
// MessageText:
//
// The entry is invalid.
//
#define EPT_S_INVALID_ENTRY              1751L

//
// MessageId: EPT_S_CANT_PERFORM_OP
//
// MessageText:
//
// The server endpoint cannot perform the operation.
//
#define EPT_S_CANT_PERFORM_OP            1752L

//
// MessageId: EPT_S_NOT_REGISTERED
//
// MessageText:
//
// There are no more endpoints available from the endpoint mapper.
//
#define EPT_S_NOT_REGISTERED             1753L

//
// MessageId: RPC_S_NOTHING_TO_EXPORT
//
// MessageText:
//
// No interfaces have been exported.
//
#define RPC_S_NOTHING_TO_EXPORT          1754L

//
// MessageId: RPC_S_INCOMPLETE_NAME
//
// MessageText:
//
// The entry name is incomplete.
//
#define RPC_S_INCOMPLETE_NAME            1755L

//
// MessageId: RPC_S_INVALID_VERS_OPTION
//
// MessageText:
//
// The version option is invalid.
//
#define RPC_S_INVALID_VERS_OPTION        1756L

//
// MessageId: RPC_S_NO_MORE_MEMBERS
//
// MessageText:
//
// There are no more members.
//
#define RPC_S_NO_MORE_MEMBERS            1757L

//
// MessageId: RPC_S_NOT_ALL_OBJS_UNEXPORTED
//
// MessageText:
//
// There is nothing to unexport.
//
#define RPC_S_NOT_ALL_OBJS_UNEXPORTED    1758L

//
// MessageId: RPC_S_INTERFACE_NOT_FOUND
//
// MessageText:
//
// The interface was not found.
//
#define RPC_S_INTERFACE_NOT_FOUND        1759L

//
// MessageId: RPC_S_ENTRY_ALREADY_EXISTS
//
// MessageText:
//
// The entry already exists.
//
#define RPC_S_ENTRY_ALREADY_EXISTS       1760L

//
// MessageId: RPC_S_ENTRY_NOT_FOUND
//
// MessageText:
//
// The entry is not found.
//
#define RPC_S_ENTRY_NOT_FOUND            1761L

//
// MessageId: RPC_S_NAME_SERVICE_UNAVAILABLE
//
// MessageText:
//
// The name service is unavailable.
//
#define RPC_S_NAME_SERVICE_UNAVAILABLE   1762L

//
// MessageId: RPC_S_INVALID_NAF_ID
//
// MessageText:
//
// The network address family is invalid.
//
#define RPC_S_INVALID_NAF_ID             1763L

//
// MessageId: RPC_S_CANNOT_SUPPORT
//
// MessageText:
//
// The requested operation is not supported.
//
#define RPC_S_CANNOT_SUPPORT             1764L

//
// MessageId: RPC_S_NO_CONTEXT_AVAILABLE
//
// MessageText:
//
// No security context is available to allow impersonation.
//
#define RPC_S_NO_CONTEXT_AVAILABLE       1765L

//
// MessageId: RPC_S_INTERNAL_ERROR
//
// MessageText:
//
// An internal error occurred in a remote procedure call (RPC).
//
#define RPC_S_INTERNAL_ERROR             1766L

//
// MessageId: RPC_S_ZERO_DIVIDE
//
// MessageText:
//
// The RPC server attempted an integer division by zero.
//
#define RPC_S_ZERO_DIVIDE                1767L

//
// MessageId: RPC_S_ADDRESS_ERROR
//
// MessageText:
//
// An addressing error occurred in the RPC server.
//
#define RPC_S_ADDRESS_ERROR              1768L

//
// MessageId: RPC_S_FP_DIV_ZERO
//
// MessageText:
//
// A floating-point operation at the RPC server caused a division by zero.
//
#define RPC_S_FP_DIV_ZERO                1769L

//
// MessageId: RPC_S_FP_UNDERFLOW
//
// MessageText:
//
// A floating-point underflow occurred at the RPC server.
//
#define RPC_S_FP_UNDERFLOW               1770L

//
// MessageId: RPC_S_FP_OVERFLOW
//
// MessageText:
//
// A floating-point overflow occurred at the RPC server.
//
#define RPC_S_FP_OVERFLOW                1771L

//
// MessageId: RPC_X_NO_MORE_ENTRIES
//
// MessageText:
//
// The list of RPC servers available for the binding of auto handles has been exhausted.
//
#define RPC_X_NO_MORE_ENTRIES            1772L

//
// MessageId: RPC_X_SS_CHAR_TRANS_OPEN_FAIL
//
// MessageText:
//
// Unable to open the character translation table file.
//
#define RPC_X_SS_CHAR_TRANS_OPEN_FAIL    1773L

//
// MessageId: RPC_X_SS_CHAR_TRANS_SHORT_FILE
//
// MessageText:
//
// The file containing the character translation table has fewer than 512 bytes.
//
#define RPC_X_SS_CHAR_TRANS_SHORT_FILE   1774L

//
// MessageId: RPC_X_SS_IN_NULL_CONTEXT
//
// MessageText:
//
// A null context handle was passed from the client to the host during a remote procedure call.
//
#define RPC_X_SS_IN_NULL_CONTEXT         1775L

//
// MessageId: RPC_X_SS_CONTEXT_DAMAGED
//
// MessageText:
//
// The context handle changed during a remote procedure call.
//
#define RPC_X_SS_CONTEXT_DAMAGED         1777L

//
// MessageId: RPC_X_SS_HANDLES_MISMATCH
//
// MessageText:
//
// The binding handles passed to a remote procedure call do not match.
//
#define RPC_X_SS_HANDLES_MISMATCH        1778L

//
// MessageId: RPC_X_SS_CANNOT_GET_CALL_HANDLE
//
// MessageText:
//
// The stub is unable to get the remote procedure call handle.
//
#define RPC_X_SS_CANNOT_GET_CALL_HANDLE  1779L

//
// MessageId: RPC_X_NULL_REF_POINTER
//
// MessageText:
//
// A null reference pointer was passed to the stub.
//
#define RPC_X_NULL_REF_POINTER           1780L

//
// MessageId: RPC_X_ENUM_VALUE_OUT_OF_RANGE
//
// MessageText:
//
// The enumeration value is out of range.
//
#define RPC_X_ENUM_VALUE_OUT_OF_RANGE    1781L

//
// MessageId: RPC_X_BYTE_COUNT_TOO_SMALL
//
// MessageText:
//
// The byte count is too small.
//
#define RPC_X_BYTE_COUNT_TOO_SMALL       1782L

//
// MessageId: RPC_X_BAD_STUB_DATA
//
// MessageText:
//
// The stub received bad data.
//
#define RPC_X_BAD_STUB_DATA              1783L

//
// MessageId: ERROR_INVALID_USER_BUFFER
//
// MessageText:
//
// The supplied user buffer is not valid for the requested operation.
//
#define ERROR_INVALID_USER_BUFFER        1784L

//
// MessageId: ERROR_UNRECOGNIZED_MEDIA
//
// MessageText:
//
// The disk media is not recognized. It may not be formatted.
//
#define ERROR_UNRECOGNIZED_MEDIA         1785L

//
// MessageId: ERROR_NO_TRUST_LSA_SECRET
//
// MessageText:
//
// The workstation does not have a trust secret.
//
#define ERROR_NO_TRUST_LSA_SECRET        1786L

//
// MessageId: ERROR_NO_TRUST_SAM_ACCOUNT
//
// MessageText:
//
// The security database on the server does not have a computer account for this workstation trust relationship.
//
#define ERROR_NO_TRUST_SAM_ACCOUNT       1787L

//
// MessageId: ERROR_TRUSTED_DOMAIN_FAILURE
//
// MessageText:
//
// The trust relationship between the primary domain and the trusted domain failed.
//
#define ERROR_TRUSTED_DOMAIN_FAILURE     1788L

//
// MessageId: ERROR_TRUSTED_RELATIONSHIP_FAILURE
//
// MessageText:
//
// The trust relationship between this workstation and the primary domain failed.
//
#define ERROR_TRUSTED_RELATIONSHIP_FAILURE 1789L

//
// MessageId: ERROR_TRUST_FAILURE
//
// MessageText:
//
// The network logon failed.
//
#define ERROR_TRUST_FAILURE              1790L

//
// MessageId: RPC_S_CALL_IN_PROGRESS
//
// MessageText:
//
// A remote procedure call is already in progress for this thread.
//
#define RPC_S_CALL_IN_PROGRESS           1791L

//
// MessageId: ERROR_NETLOGON_NOT_STARTED
//
// MessageText:
//
// An attempt was made to logon, but the network logon service was not started.
//
#define ERROR_NETLOGON_NOT_STARTED       1792L

//
// MessageId: ERROR_ACCOUNT_EXPIRED
//
// MessageText:
//
// The user's account has expired.
//
#define ERROR_ACCOUNT_EXPIRED            1793L

//
// MessageId: ERROR_REDIRECTOR_HAS_OPEN_HANDLES
//
// MessageText:
//
// The redirector is in use and cannot be unloaded.
//
#define ERROR_REDIRECTOR_HAS_OPEN_HANDLES 1794L

//
// MessageId: ERROR_PRINTER_DRIVER_ALREADY_INSTALLED
//
// MessageText:
//
// The specified printer driver is already installed.
//
#define ERROR_PRINTER_DRIVER_ALREADY_INSTALLED 1795L

//
// MessageId: ERROR_UNKNOWN_PORT
//
// MessageText:
//
// The specified port is unknown.
//
#define ERROR_UNKNOWN_PORT               1796L

//
// MessageId: ERROR_UNKNOWN_PRINTER_DRIVER
//
// MessageText:
//
// The printer driver is unknown.
//
#define ERROR_UNKNOWN_PRINTER_DRIVER     1797L

//
// MessageId: ERROR_UNKNOWN_PRINTPROCESSOR
//
// MessageText:
//
// The print processor is unknown.
//
#define ERROR_UNKNOWN_PRINTPROCESSOR     1798L

//
// MessageId: ERROR_INVALID_SEPARATOR_FILE
//
// MessageText:
//
// The specified separator file is invalid.
//
#define ERROR_INVALID_SEPARATOR_FILE     1799L

//
// MessageId: ERROR_INVALID_PRIORITY
//
// MessageText:
//
// The specified priority is invalid.
//
#define ERROR_INVALID_PRIORITY           1800L

//
// MessageId: ERROR_INVALID_PRINTER_NAME
//
// MessageText:
//
// The printer name is invalid.
//
#define ERROR_INVALID_PRINTER_NAME       1801L

//
// MessageId: ERROR_PRINTER_ALREADY_EXISTS
//
// MessageText:
//
// The printer already exists.
//
#define ERROR_PRINTER_ALREADY_EXISTS     1802L

//
// MessageId: ERROR_INVALID_PRINTER_COMMAND
//
// MessageText:
//
// The printer command is invalid.
//
#define ERROR_INVALID_PRINTER_COMMAND    1803L

//
// MessageId: ERROR_INVALID_DATATYPE
//
// MessageText:
//
// The specified datatype is invalid.
//
#define ERROR_INVALID_DATATYPE           1804L

//
// MessageId: ERROR_INVALID_ENVIRONMENT
//
// MessageText:
//
// The environment specified is invalid.
//
#define ERROR_INVALID_ENVIRONMENT        1805L

//
// MessageId: RPC_S_NO_MORE_BINDINGS
//
// MessageText:
//
// There are no more bindings.
//
#define RPC_S_NO_MORE_BINDINGS           1806L

//
// MessageId: ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT
//
// MessageText:
//
// The account used is an interdomain trust account. Use your global user account or local user account to access this server.
//
#define ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT 1807L

//
// MessageId: ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT
//
// MessageText:
//
// The account used is a computer account. Use your global user account or local user account to access this server.
//
#define ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT 1808L

//
// MessageId: ERROR_NOLOGON_SERVER_TRUST_ACCOUNT
//
// MessageText:
//
// The account used is a server trust account. Use your global user account or local user account to access this server.
//
#define ERROR_NOLOGON_SERVER_TRUST_ACCOUNT 1809L

//
// MessageId: ERROR_DOMAIN_TRUST_INCONSISTENT
//
// MessageText:
//
// The name or security ID (SID) of the domain specified is inconsistent with the trust information for that domain.
//
#define ERROR_DOMAIN_TRUST_INCONSISTENT  1810L

//
// MessageId: ERROR_SERVER_HAS_OPEN_HANDLES
//
// MessageText:
//
// The server is in use and cannot be unloaded.
//
#define ERROR_SERVER_HAS_OPEN_HANDLES    1811L

//
// MessageId: ERROR_RESOURCE_DATA_NOT_FOUND
//
// MessageText:
//
// The specified image file did not contain a resource section.
//
#define ERROR_RESOURCE_DATA_NOT_FOUND    1812L

//
// MessageId: ERROR_RESOURCE_TYPE_NOT_FOUND
//
// MessageText:
//
// The specified resource type cannot be found in the image file.
//
#define ERROR_RESOURCE_TYPE_NOT_FOUND    1813L

//
// MessageId: ERROR_RESOURCE_NAME_NOT_FOUND
//
// MessageText:
//
// The specified resource name cannot be found in the image file.
//
#define ERROR_RESOURCE_NAME_NOT_FOUND    1814L

//
// MessageId: ERROR_RESOURCE_LANG_NOT_FOUND
//
// MessageText:
//
// The specified resource language ID cannot be found in the image file.
//
#define ERROR_RESOURCE_LANG_NOT_FOUND    1815L

//
// MessageId: ERROR_NOT_ENOUGH_QUOTA
//
// MessageText:
//
// Not enough quota is available to process this command.
//
#define ERROR_NOT_ENOUGH_QUOTA           1816L

//
// MessageId: RPC_S_NO_INTERFACES
//
// MessageText:
//
// No interfaces have been registered.
//
#define RPC_S_NO_INTERFACES              1817L

//
// MessageId: RPC_S_CALL_CANCELLED
//
// MessageText:
//
// The remote procedure call was cancelled.
//
#define RPC_S_CALL_CANCELLED             1818L

//
// MessageId: RPC_S_BINDING_INCOMPLETE
//
// MessageText:
//
// The binding handle does not contain all required information.
//
#define RPC_S_BINDING_INCOMPLETE         1819L

//
// MessageId: RPC_S_COMM_FAILURE
//
// MessageText:
//
// A communications failure occurred during a remote procedure call.
//
#define RPC_S_COMM_FAILURE               1820L

//
// MessageId: RPC_S_UNSUPPORTED_AUTHN_LEVEL
//
// MessageText:
//
// The requested authentication level is not supported.
//
#define RPC_S_UNSUPPORTED_AUTHN_LEVEL    1821L

//
// MessageId: RPC_S_NO_PRINC_NAME
//
// MessageText:
//
// No principal name registered.
//
#define RPC_S_NO_PRINC_NAME              1822L

//
// MessageId: RPC_S_NOT_RPC_ERROR
//
// MessageText:
//
// The error specified is not a valid Windows RPC error code.
//
#define RPC_S_NOT_RPC_ERROR              1823L

//
// MessageId: RPC_S_UUID_LOCAL_ONLY
//
// MessageText:
//
// A UUID that is valid only on this computer has been allocated.
//
#define RPC_S_UUID_LOCAL_ONLY            1824L

//
// MessageId: RPC_S_SEC_PKG_ERROR
//
// MessageText:
//
// A security package specific error occurred.
//
#define RPC_S_SEC_PKG_ERROR              1825L

//
// MessageId: RPC_S_NOT_CANCELLED
//
// MessageText:
//
// Thread is not canceled.
//
#define RPC_S_NOT_CANCELLED              1826L

//
// MessageId: RPC_X_INVALID_ES_ACTION
//
// MessageText:
//
// Invalid operation on the encoding/decoding handle.
//
#define RPC_X_INVALID_ES_ACTION          1827L

//
// MessageId: RPC_X_WRONG_ES_VERSION
//
// MessageText:
//
// Incompatible version of the serializing package.
//
#define RPC_X_WRONG_ES_VERSION           1828L

//
// MessageId: RPC_X_WRONG_STUB_VERSION
//
// MessageText:
//
// Incompatible version of the RPC stub.
//
#define RPC_X_WRONG_STUB_VERSION         1829L

//
// MessageId: RPC_X_INVALID_PIPE_OBJECT
//
// MessageText:
//
// The RPC pipe object is invalid or corrupted.
//
#define RPC_X_INVALID_PIPE_OBJECT        1830L

//
// MessageId: RPC_X_WRONG_PIPE_ORDER
//
// MessageText:
//
// An invalid operation was attempted on an RPC pipe object.
//
#define RPC_X_WRONG_PIPE_ORDER           1831L

//
// MessageId: RPC_X_WRONG_PIPE_VERSION
//
// MessageText:
//
// Unsupported RPC pipe version.
//
#define RPC_X_WRONG_PIPE_VERSION         1832L

//
// MessageId: RPC_S_COOKIE_AUTH_FAILED
//
// MessageText:
//
// HTTP proxy server rejected the connection because the cookie authentication failed.
//
#define RPC_S_COOKIE_AUTH_FAILED         1833L

//
// MessageId: RPC_S_GROUP_MEMBER_NOT_FOUND
//
// MessageText:
//
// The group member was not found.
//
#define RPC_S_GROUP_MEMBER_NOT_FOUND     1898L

//
// MessageId: EPT_S_CANT_CREATE
//
// MessageText:
//
// The endpoint mapper database entry could not be created.
//
#define EPT_S_CANT_CREATE                1899L

//
// MessageId: RPC_S_INVALID_OBJECT
//
// MessageText:
//
// The object universal unique identifier (UUID) is the nil UUID.
//
#define RPC_S_INVALID_OBJECT             1900L

//
// MessageId: ERROR_INVALID_TIME
//
// MessageText:
//
// The specified time is invalid.
//
#define ERROR_INVALID_TIME               1901L

//
// MessageId: ERROR_INVALID_FORM_NAME
//
// MessageText:
//
// The specified form name is invalid.
//
#define ERROR_INVALID_FORM_NAME          1902L

//
// MessageId: ERROR_INVALID_FORM_SIZE
//
// MessageText:
//
// The specified form size is invalid.
//
#define ERROR_INVALID_FORM_SIZE          1903L

//
// MessageId: ERROR_ALREADY_WAITING
//
// MessageText:
//
// The specified printer handle is already being waited on
//
#define ERROR_ALREADY_WAITING            1904L

//
// MessageId: ERROR_PRINTER_DELETED
//
// MessageText:
//
// The specified printer has been deleted.
//
#define ERROR_PRINTER_DELETED            1905L

//
// MessageId: ERROR_INVALID_PRINTER_STATE
//
// MessageText:
//
// The state of the printer is invalid.
//
#define ERROR_INVALID_PRINTER_STATE      1906L

//
// MessageId: ERROR_PASSWORD_MUST_CHANGE
//
// MessageText:
//
// The user's password must be changed before logging on the first time.
//
#define ERROR_PASSWORD_MUST_CHANGE       1907L

//
// MessageId: ERROR_DOMAIN_CONTROLLER_NOT_FOUND
//
// MessageText:
//
// Could not find the domain controller for this domain.
//
#define ERROR_DOMAIN_CONTROLLER_NOT_FOUND 1908L

//
// MessageId: ERROR_ACCOUNT_LOCKED_OUT
//
// MessageText:
//
// The referenced account is currently locked out and may not be logged on to.
//
#define ERROR_ACCOUNT_LOCKED_OUT         1909L

//
// MessageId: OR_INVALID_OXID
//
// MessageText:
//
// The object exporter specified was not found.
//
#define OR_INVALID_OXID                  1910L

//
// MessageId: OR_INVALID_OID
//
// MessageText:
//
// The object specified was not found.
//
#define OR_INVALID_OID                   1911L

//
// MessageId: OR_INVALID_SET
//
// MessageText:
//
// The object resolver set specified was not found.
//
#define OR_INVALID_SET                   1912L

//
// MessageId: RPC_S_SEND_INCOMPLETE
//
// MessageText:
//
// Some data remains to be sent in the request buffer.
//
#define RPC_S_SEND_INCOMPLETE            1913L

//
// MessageId: RPC_S_INVALID_ASYNC_HANDLE
//
// MessageText:
//
// Invalid asynchronous remote procedure call handle.
//
#define RPC_S_INVALID_ASYNC_HANDLE       1914L

//
// MessageId: RPC_S_INVALID_ASYNC_CALL
//
// MessageText:
//
// Invalid asynchronous RPC call handle for this operation.
//
#define RPC_S_INVALID_ASYNC_CALL         1915L

//
// MessageId: RPC_X_PIPE_CLOSED
//
// MessageText:
//
// The RPC pipe object has already been closed.
//
#define RPC_X_PIPE_CLOSED                1916L

//
// MessageId: RPC_X_PIPE_DISCIPLINE_ERROR
//
// MessageText:
//
// The RPC call completed before all pipes were processed.
//
#define RPC_X_PIPE_DISCIPLINE_ERROR      1917L

//
// MessageId: RPC_X_PIPE_EMPTY
//
// MessageText:
//
// No more data is available from the RPC pipe.
//
#define RPC_X_PIPE_EMPTY                 1918L

//
// MessageId: ERROR_NO_SITENAME
//
// MessageText:
//
// No site name is available for this machine.
//
#define ERROR_NO_SITENAME                1919L

//
// MessageId: ERROR_CANT_ACCESS_FILE
//
// MessageText:
//
// The file cannot be accessed by the system.
//
#define ERROR_CANT_ACCESS_FILE           1920L

//
// MessageId: ERROR_CANT_RESOLVE_FILENAME
//
// MessageText:
//
// The name of the file cannot be resolved by the system.
//
#define ERROR_CANT_RESOLVE_FILENAME      1921L

//
// MessageId: RPC_S_ENTRY_TYPE_MISMATCH
//
// MessageText:
//
// The entry is not of the expected type.
//
#define RPC_S_ENTRY_TYPE_MISMATCH        1922L

//
// MessageId: RPC_S_NOT_ALL_OBJS_EXPORTED
//
// MessageText:
//
// Not all object UUIDs could be exported to the specified entry.
//
#define RPC_S_NOT_ALL_OBJS_EXPORTED      1923L

//
// MessageId: RPC_S_INTERFACE_NOT_EXPORTED
//
// MessageText:
//
// Interface could not be exported to the specified entry.
//
#define RPC_S_INTERFACE_NOT_EXPORTED     1924L

//
// MessageId: RPC_S_PROFILE_NOT_ADDED
//
// MessageText:
//
// The specified profile entry could not be added.
//
#define RPC_S_PROFILE_NOT_ADDED          1925L

//
// MessageId: RPC_S_PRF_ELT_NOT_ADDED
//
// MessageText:
//
// The specified profile element could not be added.
//
#define RPC_S_PRF_ELT_NOT_ADDED          1926L

//
// MessageId: RPC_S_PRF_ELT_NOT_REMOVED
//
// MessageText:
//
// The specified profile element could not be removed.
//
#define RPC_S_PRF_ELT_NOT_REMOVED        1927L

//
// MessageId: RPC_S_GRP_ELT_NOT_ADDED
//
// MessageText:
//
// The group element could not be added.
//
#define RPC_S_GRP_ELT_NOT_ADDED          1928L

//
// MessageId: RPC_S_GRP_ELT_NOT_REMOVED
//
// MessageText:
//
// The group element could not be removed.
//
#define RPC_S_GRP_ELT_NOT_REMOVED        1929L

//
// MessageId: ERROR_KM_DRIVER_BLOCKED
//
// MessageText:
//
// The printer driver is not compatible with a policy enabled on your computer that blocks NT 4.0 drivers.
//
#define ERROR_KM_DRIVER_BLOCKED          1930L

//
// MessageId: ERROR_CONTEXT_EXPIRED
//
// MessageText:
//
// The context has expired and can no longer be used.
//
#define ERROR_CONTEXT_EXPIRED            1931L

//
// MessageId: ERROR_PER_USER_TRUST_QUOTA_EXCEEDED
//
// MessageText:
//
// The current user's delegated trust creation quota has been exceeded.
//
#define ERROR_PER_USER_TRUST_QUOTA_EXCEEDED 1932L

//
// MessageId: ERROR_ALL_USER_TRUST_QUOTA_EXCEEDED
//
// MessageText:
//
// The total delegated trust creation quota has been exceeded.
//
#define ERROR_ALL_USER_TRUST_QUOTA_EXCEEDED 1933L

//
// MessageId: ERROR_USER_DELETE_TRUST_QUOTA_EXCEEDED
//
// MessageText:
//
// The current user's delegated trust deletion quota has been exceeded.
//
#define ERROR_USER_DELETE_TRUST_QUOTA_EXCEEDED 1934L

//
// MessageId: ERROR_AUTHENTICATION_FIREWALL_FAILED
//
// MessageText:
//
// Logon Failure: The machine you are logging onto is protected by an authentication firewall. The specified account is not allowed to authenticate to the machine.
//
#define ERROR_AUTHENTICATION_FIREWALL_FAILED 1935L

//
// MessageId: ERROR_REMOTE_PRINT_CONNECTIONS_BLOCKED
//
// MessageText:
//
// Remote connections to the Print Spooler are blocked by a policy set on your machine.
//
#define ERROR_REMOTE_PRINT_CONNECTIONS_BLOCKED 1936L

//
// MessageId: ERROR_NTLM_BLOCKED
//
// MessageText:
//
// Logon Failure: Authentication failed because NTLM authentication has been disabled. 
//
#define ERROR_NTLM_BLOCKED               1937L


///////////////////////////////////////////////////
//                                               //
//              OpenGL Error codes               //
//                                               //
//                 2000 to 2009                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_INVALID_PIXEL_FORMAT
//
// MessageText:
//
// The pixel format is invalid.
//
#define ERROR_INVALID_PIXEL_FORMAT       2000L

//
// MessageId: ERROR_BAD_DRIVER
//
// MessageText:
//
// The specified driver is invalid.
//
#define ERROR_BAD_DRIVER                 2001L

//
// MessageId: ERROR_INVALID_WINDOW_STYLE
//
// MessageText:
//
// The window style or class attribute is invalid for this operation.
//
#define ERROR_INVALID_WINDOW_STYLE       2002L

//
// MessageId: ERROR_METAFILE_NOT_SUPPORTED
//
// MessageText:
//
// The requested metafile operation is not supported.
//
#define ERROR_METAFILE_NOT_SUPPORTED     2003L

//
// MessageId: ERROR_TRANSFORM_NOT_SUPPORTED
//
// MessageText:
//
// The requested transformation operation is not supported.
//
#define ERROR_TRANSFORM_NOT_SUPPORTED    2004L

//
// MessageId: ERROR_CLIPPING_NOT_SUPPORTED
//
// MessageText:
//
// The requested clipping operation is not supported.
//
#define ERROR_CLIPPING_NOT_SUPPORTED     2005L


///////////////////////////////////////////////////
//                                               //
//       Image Color Management Error codes      //
//                                               //
//                 2010 to 2049                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_INVALID_CMM
//
// MessageText:
//
// The specified color management module is invalid.
//
#define ERROR_INVALID_CMM                2010L

//
// MessageId: ERROR_INVALID_PROFILE
//
// MessageText:
//
// The specified color profile is invalid.
//
#define ERROR_INVALID_PROFILE            2011L

//
// MessageId: ERROR_TAG_NOT_FOUND
//
// MessageText:
//
// The specified tag was not found.
//
#define ERROR_TAG_NOT_FOUND              2012L

//
// MessageId: ERROR_TAG_NOT_PRESENT
//
// MessageText:
//
// A required tag is not present.
//
#define ERROR_TAG_NOT_PRESENT            2013L

//
// MessageId: ERROR_DUPLICATE_TAG
//
// MessageText:
//
// The specified tag is already present.
//
#define ERROR_DUPLICATE_TAG              2014L

//
// MessageId: ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE
//
// MessageText:
//
// The specified color profile is not associated with the specified device.
//
#define ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE 2015L

//
// MessageId: ERROR_PROFILE_NOT_FOUND
//
// MessageText:
//
// The specified color profile was not found.
//
#define ERROR_PROFILE_NOT_FOUND          2016L

//
// MessageId: ERROR_INVALID_COLORSPACE
//
// MessageText:
//
// The specified color space is invalid.
//
#define ERROR_INVALID_COLORSPACE         2017L

//
// MessageId: ERROR_ICM_NOT_ENABLED
//
// MessageText:
//
// Image Color Management is not enabled.
//
#define ERROR_ICM_NOT_ENABLED            2018L

//
// MessageId: ERROR_DELETING_ICM_XFORM
//
// MessageText:
//
// There was an error while deleting the color transform.
//
#define ERROR_DELETING_ICM_XFORM         2019L

//
// MessageId: ERROR_INVALID_TRANSFORM
//
// MessageText:
//
// The specified color transform is invalid.
//
#define ERROR_INVALID_TRANSFORM          2020L

//
// MessageId: ERROR_COLORSPACE_MISMATCH
//
// MessageText:
//
// The specified transform does not match the bitmap's color space.
//
#define ERROR_COLORSPACE_MISMATCH        2021L

//
// MessageId: ERROR_INVALID_COLORINDEX
//
// MessageText:
//
// The specified named color index is not present in the profile.
//
#define ERROR_INVALID_COLORINDEX         2022L

//
// MessageId: ERROR_PROFILE_DOES_NOT_MATCH_DEVICE
//
// MessageText:
//
// The specified profile is intended for a device of a different type than the specified device.
//
#define ERROR_PROFILE_DOES_NOT_MATCH_DEVICE 2023L


///////////////////////////////////////////////////
//                                               //
//             Winnet32 Error codes              //
//                                               //
//                 2100 to 2999                  //
//                                               //
// The range 2100 through 2999 is reserved for   //
// network status codes. See lmerr.h for a       //
// complete listing                              //
///////////////////////////////////////////////////

//
// MessageId: ERROR_CONNECTED_OTHER_PASSWORD
//
// MessageText:
//
// The network connection was made successfully, but the user had to be prompted for a password other than the one originally specified.
//
#define ERROR_CONNECTED_OTHER_PASSWORD   2108L

//
// MessageId: ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT
//
// MessageText:
//
// The network connection was made successfully using default credentials.
//
#define ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT 2109L

//
// MessageId: ERROR_BAD_USERNAME
//
// MessageText:
//
// The specified username is invalid.
//
#define ERROR_BAD_USERNAME               2202L

//
// MessageId: ERROR_NOT_CONNECTED
//
// MessageText:
//
// This network connection does not exist.
//
#define ERROR_NOT_CONNECTED              2250L

//
// MessageId: ERROR_OPEN_FILES
//
// MessageText:
//
// This network connection has files open or requests pending.
//
#define ERROR_OPEN_FILES                 2401L

//
// MessageId: ERROR_ACTIVE_CONNECTIONS
//
// MessageText:
//
// Active connections still exist.
//
#define ERROR_ACTIVE_CONNECTIONS         2402L

//
// MessageId: ERROR_DEVICE_IN_USE
//
// MessageText:
//
// The device is in use by an active process and cannot be disconnected.
//
#define ERROR_DEVICE_IN_USE              2404L


///////////////////////////////////////////////////
//                                               //
//           Win32 Spooler Error codes           //
//                                               //
//                 3000 to 3049                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_UNKNOWN_PRINT_MONITOR
//
// MessageText:
//
// The specified print monitor is unknown.
//
#define ERROR_UNKNOWN_PRINT_MONITOR      3000L

//
// MessageId: ERROR_PRINTER_DRIVER_IN_USE
//
// MessageText:
//
// The specified printer driver is currently in use.
//
#define ERROR_PRINTER_DRIVER_IN_USE      3001L

//
// MessageId: ERROR_SPOOL_FILE_NOT_FOUND
//
// MessageText:
//
// The spool file was not found.
//
#define ERROR_SPOOL_FILE_NOT_FOUND       3002L

//
// MessageId: ERROR_SPL_NO_STARTDOC
//
// MessageText:
//
// A StartDocPrinter call was not issued.
//
#define ERROR_SPL_NO_STARTDOC            3003L

//
// MessageId: ERROR_SPL_NO_ADDJOB
//
// MessageText:
//
// An AddJob call was not issued.
//
#define ERROR_SPL_NO_ADDJOB              3004L

//
// MessageId: ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED
//
// MessageText:
//
// The specified print processor has already been installed.
//
#define ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED 3005L

//
// MessageId: ERROR_PRINT_MONITOR_ALREADY_INSTALLED
//
// MessageText:
//
// The specified print monitor has already been installed.
//
#define ERROR_PRINT_MONITOR_ALREADY_INSTALLED 3006L

//
// MessageId: ERROR_INVALID_PRINT_MONITOR
//
// MessageText:
//
// The specified print monitor does not have the required functions.
//
#define ERROR_INVALID_PRINT_MONITOR      3007L

//
// MessageId: ERROR_PRINT_MONITOR_IN_USE
//
// MessageText:
//
// The specified print monitor is currently in use.
//
#define ERROR_PRINT_MONITOR_IN_USE       3008L

//
// MessageId: ERROR_PRINTER_HAS_JOBS_QUEUED
//
// MessageText:
//
// The requested operation is not allowed when there are jobs queued to the printer.
//
#define ERROR_PRINTER_HAS_JOBS_QUEUED    3009L

//
// MessageId: ERROR_SUCCESS_REBOOT_REQUIRED
//
// MessageText:
//
// The requested operation is successful. Changes will not be effective until the system is rebooted.
//
#define ERROR_SUCCESS_REBOOT_REQUIRED    3010L

//
// MessageId: ERROR_SUCCESS_RESTART_REQUIRED
//
// MessageText:
//
// The requested operation is successful. Changes will not be effective until the service is restarted.
//
#define ERROR_SUCCESS_RESTART_REQUIRED   3011L

//
// MessageId: ERROR_PRINTER_NOT_FOUND
//
// MessageText:
//
// No printers were found.
//
#define ERROR_PRINTER_NOT_FOUND          3012L

//
// MessageId: ERROR_PRINTER_DRIVER_WARNED
//
// MessageText:
//
// The printer driver is known to be unreliable.
//
#define ERROR_PRINTER_DRIVER_WARNED      3013L

//
// MessageId: ERROR_PRINTER_DRIVER_BLOCKED
//
// MessageText:
//
// The printer driver is known to harm the system.
//
#define ERROR_PRINTER_DRIVER_BLOCKED     3014L

//
// MessageId: ERROR_PRINTER_DRIVER_PACKAGE_IN_USE
//
// MessageText:
//
// The specified printer driver package is currently in use.
//
#define ERROR_PRINTER_DRIVER_PACKAGE_IN_USE 3015L

//
// MessageId: ERROR_CORE_DRIVER_PACKAGE_NOT_FOUND
//
// MessageText:
//
// Unable to find a core driver package that is required by the printer driver package.
//
#define ERROR_CORE_DRIVER_PACKAGE_NOT_FOUND 3016L

//
// MessageId: ERROR_FAIL_REBOOT_REQUIRED
//
// MessageText:
//
// The requested operation failed. A system reboot is required to roll back changes made.
//
#define ERROR_FAIL_REBOOT_REQUIRED       3017L

//
// MessageId: ERROR_FAIL_REBOOT_INITIATED
//
// MessageText:
//
// The requested operation failed. A system reboot has been initiated to roll back changes made.
//
#define ERROR_FAIL_REBOOT_INITIATED      3018L

//
// MessageId: ERROR_PRINTER_DRIVER_DOWNLOAD_NEEDED
//
// MessageText:
//
// The specified printer driver was not found on the system and needs to be downloaded.
//
#define ERROR_PRINTER_DRIVER_DOWNLOAD_NEEDED 3019L

//
// MessageId: ERROR_PRINT_JOB_RESTART_REQUIRED
//
// MessageText:
//
// The requested print job has failed to print. A print system update requires the job to be resubmitted.
//
#define ERROR_PRINT_JOB_RESTART_REQUIRED 3020L


///////////////////////////////////////////////////
//                                               //
//                  Available                    //
//                                               //
//                 3050 to 3899                  //
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//                                               //
//                IO Error Codes                 //
//                                               //
//                 3900 to 3999                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_IO_REISSUE_AS_CACHED
//
// MessageText:
//
// Reissue the given operation as a cached IO operation
//
#define ERROR_IO_REISSUE_AS_CACHED       3950L



///////////////////////////////////////////////////
//                                               //
//                Wins Error codes               //
//                                               //
//                 4000 to 4049                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_WINS_INTERNAL
//
// MessageText:
//
// WINS encountered an error while processing the command.
//
#define ERROR_WINS_INTERNAL              4000L

//
// MessageId: ERROR_CAN_NOT_DEL_LOCAL_WINS
//
// MessageText:
//
// The local WINS cannot be deleted.
//
#define ERROR_CAN_NOT_DEL_LOCAL_WINS     4001L

//
// MessageId: ERROR_STATIC_INIT
//
// MessageText:
//
// The importation from the file failed.
//
#define ERROR_STATIC_INIT                4002L

//
// MessageId: ERROR_INC_BACKUP
//
// MessageText:
//
// The backup failed. Was a full backup done before?
//
#define ERROR_INC_BACKUP                 4003L

//
// MessageId: ERROR_FULL_BACKUP
//
// MessageText:
//
// The backup failed. Check the directory to which you are backing the database.
//
#define ERROR_FULL_BACKUP                4004L

//
// MessageId: ERROR_REC_NON_EXISTENT
//
// MessageText:
//
// The name does not exist in the WINS database.
//
#define ERROR_REC_NON_EXISTENT           4005L

//
// MessageId: ERROR_RPL_NOT_ALLOWED
//
// MessageText:
//
// Replication with a nonconfigured partner is not allowed.
//
#define ERROR_RPL_NOT_ALLOWED            4006L


///////////////////////////////////////////////////
//                                               //
//                  Available                    //
//                                               //
//                 4050 to 4099                  //
///////////////////////////////////////////////////

///////////////////////////////////////////////////
//                                               //
//               DHCP Error codes                //
//                                               //
//                 4100 to 4149                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_DHCP_ADDRESS_CONFLICT
//
// MessageText:
//
// The DHCP client has obtained an IP address that is already in use on the network. The local interface will be disabled until the DHCP client can obtain a new address.
//
#define ERROR_DHCP_ADDRESS_CONFLICT      4100L


///////////////////////////////////////////////////
//                                               //
//                  Available                    //
//                                               //
//                 4150 to 4199                  //
///////////////////////////////////////////////////

///////////////////////////////////////////////////
//                                               //
//               WMI Error codes                 //
//                                               //
//                 4200 to 4249                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_WMI_GUID_NOT_FOUND
//
// MessageText:
//
// The GUID passed was not recognized as valid by a WMI data provider.
//
#define ERROR_WMI_GUID_NOT_FOUND         4200L

//
// MessageId: ERROR_WMI_INSTANCE_NOT_FOUND
//
// MessageText:
//
// The instance name passed was not recognized as valid by a WMI data provider.
//
#define ERROR_WMI_INSTANCE_NOT_FOUND     4201L

//
// MessageId: ERROR_WMI_ITEMID_NOT_FOUND
//
// MessageText:
//
// The data item ID passed was not recognized as valid by a WMI data provider.
//
#define ERROR_WMI_ITEMID_NOT_FOUND       4202L

//
// MessageId: ERROR_WMI_TRY_AGAIN
//
// MessageText:
//
// The WMI request could not be completed and should be retried.
//
#define ERROR_WMI_TRY_AGAIN              4203L

//
// MessageId: ERROR_WMI_DP_NOT_FOUND
//
// MessageText:
//
// The WMI data provider could not be located.
//
#define ERROR_WMI_DP_NOT_FOUND           4204L

//
// MessageId: ERROR_WMI_UNRESOLVED_INSTANCE_REF
//
// MessageText:
//
// The WMI data provider references an instance set that has not been registered.
//
#define ERROR_WMI_UNRESOLVED_INSTANCE_REF 4205L

//
// MessageId: ERROR_WMI_ALREADY_ENABLED
//
// MessageText:
//
// The WMI data block or event notification has already been enabled.
//
#define ERROR_WMI_ALREADY_ENABLED        4206L

//
// MessageId: ERROR_WMI_GUID_DISCONNECTED
//
// MessageText:
//
// The WMI data block is no longer available.
//
#define ERROR_WMI_GUID_DISCONNECTED      4207L

//
// MessageId: ERROR_WMI_SERVER_UNAVAILABLE
//
// MessageText:
//
// The WMI data service is not available.
//
#define ERROR_WMI_SERVER_UNAVAILABLE     4208L

//
// MessageId: ERROR_WMI_DP_FAILED
//
// MessageText:
//
// The WMI data provider failed to carry out the request.
//
#define ERROR_WMI_DP_FAILED              4209L

//
// MessageId: ERROR_WMI_INVALID_MOF
//
// MessageText:
//
// The WMI MOF information is not valid.
//
#define ERROR_WMI_INVALID_MOF            4210L

//
// MessageId: ERROR_WMI_INVALID_REGINFO
//
// MessageText:
//
// The WMI registration information is not valid.
//
#define ERROR_WMI_INVALID_REGINFO        4211L

//
// MessageId: ERROR_WMI_ALREADY_DISABLED
//
// MessageText:
//
// The WMI data block or event notification has already been disabled.
//
#define ERROR_WMI_ALREADY_DISABLED       4212L

//
// MessageId: ERROR_WMI_READ_ONLY
//
// MessageText:
//
// The WMI data item or data block is read only.
//
#define ERROR_WMI_READ_ONLY              4213L

//
// MessageId: ERROR_WMI_SET_FAILURE
//
// MessageText:
//
// The WMI data item or data block could not be changed.
//
#define ERROR_WMI_SET_FAILURE            4214L


///////////////////////////////////////////////////
//                                               //
//                  Available                    //
//                                               //
//                 4250 to 4299                  //
///////////////////////////////////////////////////

///////////////////////////////////////////////////
//                                               //
//        RSM (Media Services) Error codes       //
//                                               //
//                 4300 to 4349                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_INVALID_MEDIA
//
// MessageText:
//
// The media identifier does not represent a valid medium.
//
#define ERROR_INVALID_MEDIA              4300L

//
// MessageId: ERROR_INVALID_LIBRARY
//
// MessageText:
//
// The library identifier does not represent a valid library.
//
#define ERROR_INVALID_LIBRARY            4301L

//
// MessageId: ERROR_INVALID_MEDIA_POOL
//
// MessageText:
//
// The media pool identifier does not represent a valid media pool.
//
#define ERROR_INVALID_MEDIA_POOL         4302L

//
// MessageId: ERROR_DRIVE_MEDIA_MISMATCH
//
// MessageText:
//
// The drive and medium are not compatible or exist in different libraries.
//
#define ERROR_DRIVE_MEDIA_MISMATCH       4303L

//
// MessageId: ERROR_MEDIA_OFFLINE
//
// MessageText:
//
// The medium currently exists in an offline library and must be online to perform this operation.
//
#define ERROR_MEDIA_OFFLINE              4304L

//
// MessageId: ERROR_LIBRARY_OFFLINE
//
// MessageText:
//
// The operation cannot be performed on an offline library.
//
#define ERROR_LIBRARY_OFFLINE            4305L

//
// MessageId: ERROR_EMPTY
//
// MessageText:
//
// The library, drive, or media pool is empty.
//
#define ERROR_EMPTY                      4306L

//
// MessageId: ERROR_NOT_EMPTY
//
// MessageText:
//
// The library, drive, or media pool must be empty to perform this operation.
//
#define ERROR_NOT_EMPTY                  4307L

//
// MessageId: ERROR_MEDIA_UNAVAILABLE
//
// MessageText:
//
// No media is currently available in this media pool or library.
//
#define ERROR_MEDIA_UNAVAILABLE          4308L

//
// MessageId: ERROR_RESOURCE_DISABLED
//
// MessageText:
//
// A resource required for this operation is disabled.
//
#define ERROR_RESOURCE_DISABLED          4309L

//
// MessageId: ERROR_INVALID_CLEANER
//
// MessageText:
//
// The media identifier does not represent a valid cleaner.
//
#define ERROR_INVALID_CLEANER            4310L

//
// MessageId: ERROR_UNABLE_TO_CLEAN
//
// MessageText:
//
// The drive cannot be cleaned or does not support cleaning.
//
#define ERROR_UNABLE_TO_CLEAN            4311L

//
// MessageId: ERROR_OBJECT_NOT_FOUND
//
// MessageText:
//
// The object identifier does not represent a valid object.
//
#define ERROR_OBJECT_NOT_FOUND           4312L

//
// MessageId: ERROR_DATABASE_FAILURE
//
// MessageText:
//
// Unable to read from or write to the database.
//
#define ERROR_DATABASE_FAILURE           4313L

//
// MessageId: ERROR_DATABASE_FULL
//
// MessageText:
//
// The database is full.
//
#define ERROR_DATABASE_FULL              4314L

//
// MessageId: ERROR_MEDIA_INCOMPATIBLE
//
// MessageText:
//
// The medium is not compatible with the device or media pool.
//
#define ERROR_MEDIA_INCOMPATIBLE         4315L

//
// MessageId: ERROR_RESOURCE_NOT_PRESENT
//
// MessageText:
//
// The resource required for this operation does not exist.
//
#define ERROR_RESOURCE_NOT_PRESENT       4316L

//
// MessageId: ERROR_INVALID_OPERATION
//
// MessageText:
//
// The operation identifier is not valid.
//
#define ERROR_INVALID_OPERATION          4317L

//
// MessageId: ERROR_MEDIA_NOT_AVAILABLE
//
// MessageText:
//
// The media is not mounted or ready for use.
//
#define ERROR_MEDIA_NOT_AVAILABLE        4318L

//
// MessageId: ERROR_DEVICE_NOT_AVAILABLE
//
// MessageText:
//
// The device is not ready for use.
//
#define ERROR_DEVICE_NOT_AVAILABLE       4319L

//
// MessageId: ERROR_REQUEST_REFUSED
//
// MessageText:
//
// The operator or administrator has refused the request.
//
#define ERROR_REQUEST_REFUSED            4320L

//
// MessageId: ERROR_INVALID_DRIVE_OBJECT
//
// MessageText:
//
// The drive identifier does not represent a valid drive.
//
#define ERROR_INVALID_DRIVE_OBJECT       4321L

//
// MessageId: ERROR_LIBRARY_FULL
//
// MessageText:
//
// Library is full. No slot is available for use.
//
#define ERROR_LIBRARY_FULL               4322L

//
// MessageId: ERROR_MEDIUM_NOT_ACCESSIBLE
//
// MessageText:
//
// The transport cannot access the medium.
//
#define ERROR_MEDIUM_NOT_ACCESSIBLE      4323L

//
// MessageId: ERROR_UNABLE_TO_LOAD_MEDIUM
//
// MessageText:
//
// Unable to load the medium into the drive.
//
#define ERROR_UNABLE_TO_LOAD_MEDIUM      4324L

//
// MessageId: ERROR_UNABLE_TO_INVENTORY_DRIVE
//
// MessageText:
//
// Unable to retrieve the drive status.
//
#define ERROR_UNABLE_TO_INVENTORY_DRIVE  4325L

//
// MessageId: ERROR_UNABLE_TO_INVENTORY_SLOT
//
// MessageText:
//
// Unable to retrieve the slot status.
//
#define ERROR_UNABLE_TO_INVENTORY_SLOT   4326L

//
// MessageId: ERROR_UNABLE_TO_INVENTORY_TRANSPORT
//
// MessageText:
//
// Unable to retrieve status about the transport.
//
#define ERROR_UNABLE_TO_INVENTORY_TRANSPORT 4327L

//
// MessageId: ERROR_TRANSPORT_FULL
//
// MessageText:
//
// Cannot use the transport because it is already in use.
//
#define ERROR_TRANSPORT_FULL             4328L

//
// MessageId: ERROR_CONTROLLING_IEPORT
//
// MessageText:
//
// Unable to open or close the inject/eject port.
//
#define ERROR_CONTROLLING_IEPORT         4329L

//
// MessageId: ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA
//
// MessageText:
//
// Unable to eject the medium because it is in a drive.
//
#define ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA 4330L

//
// MessageId: ERROR_CLEANER_SLOT_SET
//
// MessageText:
//
// A cleaner slot is already reserved.
//
#define ERROR_CLEANER_SLOT_SET           4331L

//
// MessageId: ERROR_CLEANER_SLOT_NOT_SET
//
// MessageText:
//
// A cleaner slot is not reserved.
//
#define ERROR_CLEANER_SLOT_NOT_SET       4332L

//
// MessageId: ERROR_CLEANER_CARTRIDGE_SPENT
//
// MessageText:
//
// The cleaner cartridge has performed the maximum number of drive cleanings.
//
#define ERROR_CLEANER_CARTRIDGE_SPENT    4333L

//
// MessageId: ERROR_UNEXPECTED_OMID
//
// MessageText:
//
// Unexpected on-medium identifier.
//
#define ERROR_UNEXPECTED_OMID            4334L

//
// MessageId: ERROR_CANT_DELETE_LAST_ITEM
//
// MessageText:
//
// The last remaining item in this group or resource cannot be deleted.
//
#define ERROR_CANT_DELETE_LAST_ITEM      4335L

//
// MessageId: ERROR_MESSAGE_EXCEEDS_MAX_SIZE
//
// MessageText:
//
// The message provided exceeds the maximum size allowed for this parameter.
//
#define ERROR_MESSAGE_EXCEEDS_MAX_SIZE   4336L

//
// MessageId: ERROR_VOLUME_CONTAINS_SYS_FILES
//
// MessageText:
//
// The volume contains system or paging files.
//
#define ERROR_VOLUME_CONTAINS_SYS_FILES  4337L

//
// MessageId: ERROR_INDIGENOUS_TYPE
//
// MessageText:
//
// The media type cannot be removed from this library since at least one drive in the library reports it can support this media type.
//
#define ERROR_INDIGENOUS_TYPE            4338L

//
// MessageId: ERROR_NO_SUPPORTING_DRIVES
//
// MessageText:
//
// This offline media cannot be mounted on this system since no enabled drives are present which can be used.
//
#define ERROR_NO_SUPPORTING_DRIVES       4339L

//
// MessageId: ERROR_CLEANER_CARTRIDGE_INSTALLED
//
// MessageText:
//
// A cleaner cartridge is present in the tape library.
//
#define ERROR_CLEANER_CARTRIDGE_INSTALLED 4340L

//
// MessageId: ERROR_IEPORT_FULL
//
// MessageText:
//
// Cannot use the ieport because it is not empty.
//
#define ERROR_IEPORT_FULL                4341L


///////////////////////////////////////////////////
//                                               //
//       Remote Storage Service Error codes      //
//                                               //
//                 4350 to 4389                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_FILE_OFFLINE
//
// MessageText:
//
// This file is currently not available for use on this computer.
//
#define ERROR_FILE_OFFLINE               4350L

//
// MessageId: ERROR_REMOTE_STORAGE_NOT_ACTIVE
//
// MessageText:
//
// The remote storage service is not operational at this time.
//
#define ERROR_REMOTE_STORAGE_NOT_ACTIVE  4351L

//
// MessageId: ERROR_REMOTE_STORAGE_MEDIA_ERROR
//
// MessageText:
//
// The remote storage service encountered a media error.
//
#define ERROR_REMOTE_STORAGE_MEDIA_ERROR 4352L


///////////////////////////////////////////////////
//                                               //
//           Reparse Point Error codes           //
//                                               //
//                 4390 to 4399                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_NOT_A_REPARSE_POINT
//
// MessageText:
//
// The file or directory is not a reparse point.
//
#define ERROR_NOT_A_REPARSE_POINT        4390L

//
// MessageId: ERROR_REPARSE_ATTRIBUTE_CONFLICT
//
// MessageText:
//
// The reparse point attribute cannot be set because it conflicts with an existing attribute.
//
#define ERROR_REPARSE_ATTRIBUTE_CONFLICT 4391L

//
// MessageId: ERROR_INVALID_REPARSE_DATA
//
// MessageText:
//
// The data present in the reparse point buffer is invalid.
//
#define ERROR_INVALID_REPARSE_DATA       4392L

//
// MessageId: ERROR_REPARSE_TAG_INVALID
//
// MessageText:
//
// The tag present in the reparse point buffer is invalid.
//
#define ERROR_REPARSE_TAG_INVALID        4393L

//
// MessageId: ERROR_REPARSE_TAG_MISMATCH
//
// MessageText:
//
// There is a mismatch between the tag specified in the request and the tag present in the reparse point.
// 
//
#define ERROR_REPARSE_TAG_MISMATCH       4394L


///////////////////////////////////////////////////
//                                               //
//                  Available                    //
//                                               //
//                 4400 to 4499                  //
///////////////////////////////////////////////////

///////////////////////////////////////////////////
//                                               //
//    Single Instance Store (SIS) Error codes    //
//                                               //
//                 4500 to 4549                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_VOLUME_NOT_SIS_ENABLED
//
// MessageText:
//
// Single Instance Storage is not available on this volume.
//
#define ERROR_VOLUME_NOT_SIS_ENABLED     4500L

///////////////////////////////////////////////////
//                                               //
//                  Available                    //
//                                               //
//                 4550 to 4599                  //
///////////////////////////////////////////////////

///////////////////////////////////////////////////
//                                               //
//             Cluster Error codes               //
//                                               //
//                 5000 to 5999                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_DEPENDENT_RESOURCE_EXISTS
//
// MessageText:
//
// The operation cannot be completed because other resources are dependent on this resource.
//
#define ERROR_DEPENDENT_RESOURCE_EXISTS  5001L

//
// MessageId: ERROR_DEPENDENCY_NOT_FOUND
//
// MessageText:
//
// The cluster resource dependency cannot be found.
//
#define ERROR_DEPENDENCY_NOT_FOUND       5002L

//
// MessageId: ERROR_DEPENDENCY_ALREADY_EXISTS
//
// MessageText:
//
// The cluster resource cannot be made dependent on the specified resource because it is already dependent.
//
#define ERROR_DEPENDENCY_ALREADY_EXISTS  5003L

//
// MessageId: ERROR_RESOURCE_NOT_ONLINE
//
// MessageText:
//
// The cluster resource is not online.
//
#define ERROR_RESOURCE_NOT_ONLINE        5004L

//
// MessageId: ERROR_HOST_NODE_NOT_AVAILABLE
//
// MessageText:
//
// A cluster node is not available for this operation.
//
#define ERROR_HOST_NODE_NOT_AVAILABLE    5005L

//
// MessageId: ERROR_RESOURCE_NOT_AVAILABLE
//
// MessageText:
//
// The cluster resource is not available.
//
#define ERROR_RESOURCE_NOT_AVAILABLE     5006L

//
// MessageId: ERROR_RESOURCE_NOT_FOUND
//
// MessageText:
//
// The cluster resource could not be found.
//
#define ERROR_RESOURCE_NOT_FOUND         5007L

//
// MessageId: ERROR_SHUTDOWN_CLUSTER
//
// MessageText:
//
// The cluster is being shut down.
//
#define ERROR_SHUTDOWN_CLUSTER           5008L

//
// MessageId: ERROR_CANT_EVICT_ACTIVE_NODE
//
// MessageText:
//
// A cluster node cannot be evicted from the cluster unless the node is down or it is the last node.
//
#define ERROR_CANT_EVICT_ACTIVE_NODE     5009L

//
// MessageId: ERROR_OBJECT_ALREADY_EXISTS
//
// MessageText:
//
// The object already exists.
//
#define ERROR_OBJECT_ALREADY_EXISTS      5010L

//
// MessageId: ERROR_OBJECT_IN_LIST
//
// MessageText:
//
// The object is already in the list.
//
#define ERROR_OBJECT_IN_LIST             5011L

//
// MessageId: ERROR_GROUP_NOT_AVAILABLE
//
// MessageText:
//
// The cluster group is not available for any new requests.
//
#define ERROR_GROUP_NOT_AVAILABLE        5012L

//
// MessageId: ERROR_GROUP_NOT_FOUND
//
// MessageText:
//
// The cluster group could not be found.
//
#define ERROR_GROUP_NOT_FOUND            5013L

//
// MessageId: ERROR_GROUP_NOT_ONLINE
//
// MessageText:
//
// The operation could not be completed because the cluster group is not online.
//
#define ERROR_GROUP_NOT_ONLINE           5014L

//
// MessageId: ERROR_HOST_NODE_NOT_RESOURCE_OWNER
//
// MessageText:
//
// The operation failed because either the specified cluster node is not the owner of the resource, or the node
// is not a possible owner of the resource.
//
#define ERROR_HOST_NODE_NOT_RESOURCE_OWNER 5015L

//
// MessageId: ERROR_HOST_NODE_NOT_GROUP_OWNER
//
// MessageText:
//
// The operation failed because either the specified cluster node is not the owner of the group, or the node
// is not a possible owner of the group.
//
#define ERROR_HOST_NODE_NOT_GROUP_OWNER  5016L

//
// MessageId: ERROR_RESMON_CREATE_FAILED
//
// MessageText:
//
// The cluster resource could not be created in the specified resource monitor.
//
#define ERROR_RESMON_CREATE_FAILED       5017L

//
// MessageId: ERROR_RESMON_ONLINE_FAILED
//
// MessageText:
//
// The cluster resource could not be brought online by the resource monitor.
//
#define ERROR_RESMON_ONLINE_FAILED       5018L

//
// MessageId: ERROR_RESOURCE_ONLINE
//
// MessageText:
//
// The operation could not be completed because the cluster resource is online.
//
#define ERROR_RESOURCE_ONLINE            5019L

//
// MessageId: ERROR_QUORUM_RESOURCE
//
// MessageText:
//
// The cluster resource could not be deleted or brought offline because it is the quorum resource.
//
#define ERROR_QUORUM_RESOURCE            5020L

//
// MessageId: ERROR_NOT_QUORUM_CAPABLE
//
// MessageText:
//
// The cluster could not make the specified resource a quorum resource because it is not capable of being a quorum resource.
//
#define ERROR_NOT_QUORUM_CAPABLE         5021L

//
// MessageId: ERROR_CLUSTER_SHUTTING_DOWN
//
// MessageText:
//
// The cluster software is shutting down.
//
#define ERROR_CLUSTER_SHUTTING_DOWN      5022L

//
// MessageId: ERROR_INVALID_STATE
//
// MessageText:
//
// The group or resource is not in the correct state to perform the requested operation.
//
#define ERROR_INVALID_STATE              5023L

//
// MessageId: ERROR_RESOURCE_PROPERTIES_STORED
//
// MessageText:
//
// The properties were stored but not all changes will take effect until the next time the resource is brought online.
//
#define ERROR_RESOURCE_PROPERTIES_STORED 5024L

//
// MessageId: ERROR_NOT_QUORUM_CLASS
//
// MessageText:
//
// The cluster could not make the specified resource a quorum resource because it does not belong to a shared storage class.
//
#define ERROR_NOT_QUORUM_CLASS           5025L

//
// MessageId: ERROR_CORE_RESOURCE
//
// MessageText:
//
// The cluster resource could not be deleted since it is a core resource.
//
#define ERROR_CORE_RESOURCE              5026L

//
// MessageId: ERROR_QUORUM_RESOURCE_ONLINE_FAILED
//
// MessageText:
//
// The quorum resource failed to come online.
//
#define ERROR_QUORUM_RESOURCE_ONLINE_FAILED 5027L

//
// MessageId: ERROR_QUORUMLOG_OPEN_FAILED
//
// MessageText:
//
// The quorum log could not be created or mounted successfully.
//
#define ERROR_QUORUMLOG_OPEN_FAILED      5028L

//
// MessageId: ERROR_CLUSTERLOG_CORRUPT
//
// MessageText:
//
// The cluster log is corrupt.
//
#define ERROR_CLUSTERLOG_CORRUPT         5029L

//
// MessageId: ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE
//
// MessageText:
//
// The record could not be written to the cluster log since it exceeds the maximum size.
//
#define ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE 5030L

//
// MessageId: ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE
//
// MessageText:
//
// The cluster log exceeds its maximum size.
//
#define ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE 5031L

//
// MessageId: ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND
//
// MessageText:
//
// No checkpoint record was found in the cluster log.
//
#define ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND 5032L

//
// MessageId: ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE
//
// MessageText:
//
// The minimum required disk space needed for logging is not available.
//
#define ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE 5033L

//
// MessageId: ERROR_QUORUM_OWNER_ALIVE
//
// MessageText:
//
// The cluster node failed to take control of the quorum resource because the resource is owned by another active node.
//
#define ERROR_QUORUM_OWNER_ALIVE         5034L

//
// MessageId: ERROR_NETWORK_NOT_AVAILABLE
//
// MessageText:
//
// A cluster network is not available for this operation.
//
#define ERROR_NETWORK_NOT_AVAILABLE      5035L

//
// MessageId: ERROR_NODE_NOT_AVAILABLE
//
// MessageText:
//
// A cluster node is not available for this operation.
//
#define ERROR_NODE_NOT_AVAILABLE         5036L

//
// MessageId: ERROR_ALL_NODES_NOT_AVAILABLE
//
// MessageText:
//
// All cluster nodes must be running to perform this operation.
//
#define ERROR_ALL_NODES_NOT_AVAILABLE    5037L

//
// MessageId: ERROR_RESOURCE_FAILED
//
// MessageText:
//
// A cluster resource failed.
//
#define ERROR_RESOURCE_FAILED            5038L

//
// MessageId: ERROR_CLUSTER_INVALID_NODE
//
// MessageText:
//
// The cluster node is not valid.
//
#define ERROR_CLUSTER_INVALID_NODE       5039L

//
// MessageId: ERROR_CLUSTER_NODE_EXISTS
//
// MessageText:
//
// The cluster node already exists.
//
#define ERROR_CLUSTER_NODE_EXISTS        5040L

//
// MessageId: ERROR_CLUSTER_JOIN_IN_PROGRESS
//
// MessageText:
//
// A node is in the process of joining the cluster.
//
#define ERROR_CLUSTER_JOIN_IN_PROGRESS   5041L

//
// MessageId: ERROR_CLUSTER_NODE_NOT_FOUND
//
// MessageText:
//
// The cluster node was not found.
//
#define ERROR_CLUSTER_NODE_NOT_FOUND     5042L

//
// MessageId: ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND
//
// MessageText:
//
// The cluster local node information was not found.
//
#define ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND 5043L

//
// MessageId: ERROR_CLUSTER_NETWORK_EXISTS
//
// MessageText:
//
// The cluster network already exists.
//
#define ERROR_CLUSTER_NETWORK_EXISTS     5044L

//
// MessageId: ERROR_CLUSTER_NETWORK_NOT_FOUND
//
// MessageText:
//
// The cluster network was not found.
//
#define ERROR_CLUSTER_NETWORK_NOT_FOUND  5045L

//
// MessageId: ERROR_CLUSTER_NETINTERFACE_EXISTS
//
// MessageText:
//
// The cluster network interface already exists.
//
#define ERROR_CLUSTER_NETINTERFACE_EXISTS 5046L

//
// MessageId: ERROR_CLUSTER_NETINTERFACE_NOT_FOUND
//
// MessageText:
//
// The cluster network interface was not found.
//
#define ERROR_CLUSTER_NETINTERFACE_NOT_FOUND 5047L

//
// MessageId: ERROR_CLUSTER_INVALID_REQUEST
//
// MessageText:
//
// The cluster request is not valid for this object.
//
#define ERROR_CLUSTER_INVALID_REQUEST    5048L

//
// MessageId: ERROR_CLUSTER_INVALID_NETWORK_PROVIDER
//
// MessageText:
//
// The cluster network provider is not valid.
//
#define ERROR_CLUSTER_INVALID_NETWORK_PROVIDER 5049L

//
// MessageId: ERROR_CLUSTER_NODE_DOWN
//
// MessageText:
//
// The cluster node is down.
//
#define ERROR_CLUSTER_NODE_DOWN          5050L

//
// MessageId: ERROR_CLUSTER_NODE_UNREACHABLE
//
// MessageText:
//
// The cluster node is not reachable.
//
#define ERROR_CLUSTER_NODE_UNREACHABLE   5051L

//
// MessageId: ERROR_CLUSTER_NODE_NOT_MEMBER
//
// MessageText:
//
// The cluster node is not a member of the cluster.
//
#define ERROR_CLUSTER_NODE_NOT_MEMBER    5052L

//
// MessageId: ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS
//
// MessageText:
//
// A cluster join operation is not in progress.
//
#define ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS 5053L

//
// MessageId: ERROR_CLUSTER_INVALID_NETWORK
//
// MessageText:
//
// The cluster network is not valid.
//
#define ERROR_CLUSTER_INVALID_NETWORK    5054L

//
// MessageId: ERROR_CLUSTER_NODE_UP
//
// MessageText:
//
// The cluster node is up.
//
#define ERROR_CLUSTER_NODE_UP            5056L

//
// MessageId: ERROR_CLUSTER_IPADDR_IN_USE
//
// MessageText:
//
// The cluster IP address is already in use.
//
#define ERROR_CLUSTER_IPADDR_IN_USE      5057L

//
// MessageId: ERROR_CLUSTER_NODE_NOT_PAUSED
//
// MessageText:
//
// The cluster node is not paused.
//
#define ERROR_CLUSTER_NODE_NOT_PAUSED    5058L

//
// MessageId: ERROR_CLUSTER_NO_SECURITY_CONTEXT
//
// MessageText:
//
// No cluster security context is available.
//
#define ERROR_CLUSTER_NO_SECURITY_CONTEXT 5059L

//
// MessageId: ERROR_CLUSTER_NETWORK_NOT_INTERNAL
//
// MessageText:
//
// The cluster network is not configured for internal cluster communication.
//
#define ERROR_CLUSTER_NETWORK_NOT_INTERNAL 5060L

//
// MessageId: ERROR_CLUSTER_NODE_ALREADY_UP
//
// MessageText:
//
// The cluster node is already up.
//
#define ERROR_CLUSTER_NODE_ALREADY_UP    5061L

//
// MessageId: ERROR_CLUSTER_NODE_ALREADY_DOWN
//
// MessageText:
//
// The cluster node is already down.
//
#define ERROR_CLUSTER_NODE_ALREADY_DOWN  5062L

//
// MessageId: ERROR_CLUSTER_NETWORK_ALREADY_ONLINE
//
// MessageText:
//
// The cluster network is already online.
//
#define ERROR_CLUSTER_NETWORK_ALREADY_ONLINE 5063L

//
// MessageId: ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE
//
// MessageText:
//
// The cluster network is already offline.
//
#define ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE 5064L

//
// MessageId: ERROR_CLUSTER_NODE_ALREADY_MEMBER
//
// MessageText:
//
// The cluster node is already a member of the cluster.
//
#define ERROR_CLUSTER_NODE_ALREADY_MEMBER 5065L

//
// MessageId: ERROR_CLUSTER_LAST_INTERNAL_NETWORK
//
// MessageText:
//
// The cluster network is the only one configured for internal cluster communication between two or more active cluster nodes. The internal communication capability cannot be removed from the network.
//
#define ERROR_CLUSTER_LAST_INTERNAL_NETWORK 5066L

//
// MessageId: ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS
//
// MessageText:
//
// One or more cluster resources depend on the network to provide service to clients. The client access capability cannot be removed from the network.
//
#define ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS 5067L

//
// MessageId: ERROR_INVALID_OPERATION_ON_QUORUM
//
// MessageText:
//
// This operation cannot be performed on the cluster resource as it the quorum resource. You may not bring the quorum resource offline or modify its possible owners list.
//
#define ERROR_INVALID_OPERATION_ON_QUORUM 5068L

//
// MessageId: ERROR_DEPENDENCY_NOT_ALLOWED
//
// MessageText:
//
// The cluster quorum resource is not allowed to have any dependencies.
//
#define ERROR_DEPENDENCY_NOT_ALLOWED     5069L

//
// MessageId: ERROR_CLUSTER_NODE_PAUSED
//
// MessageText:
//
// The cluster node is paused.
//
#define ERROR_CLUSTER_NODE_PAUSED        5070L

//
// MessageId: ERROR_NODE_CANT_HOST_RESOURCE
//
// MessageText:
//
// The cluster resource cannot be brought online. The owner node cannot run this resource.
//
#define ERROR_NODE_CANT_HOST_RESOURCE    5071L

//
// MessageId: ERROR_CLUSTER_NODE_NOT_READY
//
// MessageText:
//
// The cluster node is not ready to perform the requested operation.
//
#define ERROR_CLUSTER_NODE_NOT_READY     5072L

//
// MessageId: ERROR_CLUSTER_NODE_SHUTTING_DOWN
//
// MessageText:
//
// The cluster node is shutting down.
//
#define ERROR_CLUSTER_NODE_SHUTTING_DOWN 5073L

//
// MessageId: ERROR_CLUSTER_JOIN_ABORTED
//
// MessageText:
//
// The cluster join operation was aborted.
//
#define ERROR_CLUSTER_JOIN_ABORTED       5074L

//
// MessageId: ERROR_CLUSTER_INCOMPATIBLE_VERSIONS
//
// MessageText:
//
// The cluster join operation failed due to incompatible software versions between the joining node and its sponsor.
//
#define ERROR_CLUSTER_INCOMPATIBLE_VERSIONS 5075L

//
// MessageId: ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED
//
// MessageText:
//
// This resource cannot be created because the cluster has reached the limit on the number of resources it can monitor.
//
#define ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED 5076L

//
// MessageId: ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED
//
// MessageText:
//
// The system configuration changed during the cluster join or form operation. The join or form operation was aborted.
//
#define ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED 5077L

//
// MessageId: ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND
//
// MessageText:
//
// The specified resource type was not found.
//
#define ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND 5078L

//
// MessageId: ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED
//
// MessageText:
//
// The specified node does not support a resource of this type. This may be due to version inconsistencies or due to the absence of the resource DLL on this node.
//
#define ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED 5079L

//
// MessageId: ERROR_CLUSTER_RESNAME_NOT_FOUND
//
// MessageText:
//
// The specified resource name is not supported by this resource DLL. This may be due to a bad (or changed) name supplied to the resource DLL.
//
#define ERROR_CLUSTER_RESNAME_NOT_FOUND  5080L

//
// MessageId: ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED
//
// MessageText:
//
// No authentication package could be registered with the RPC server.
//
#define ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED 5081L

//
// MessageId: ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST
//
// MessageText:
//
// You cannot bring the group online because the owner of the group is not in the preferred list for the group. To change the owner node for the group, move the group.
//
#define ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST 5082L

//
// MessageId: ERROR_CLUSTER_DATABASE_SEQMISMATCH
//
// MessageText:
//
// The join operation failed because the cluster database sequence number has changed or is incompatible with the locker node. This may happen during a join operation if the cluster database was changing during the join.
//
#define ERROR_CLUSTER_DATABASE_SEQMISMATCH 5083L

//
// MessageId: ERROR_RESMON_INVALID_STATE
//
// MessageText:
//
// The resource monitor will not allow the fail operation to be performed while the resource is in its current state. This may happen if the resource is in a pending state.
//
#define ERROR_RESMON_INVALID_STATE       5084L

//
// MessageId: ERROR_CLUSTER_GUM_NOT_LOCKER
//
// MessageText:
//
// A non locker code got a request to reserve the lock for making global updates.
//
#define ERROR_CLUSTER_GUM_NOT_LOCKER     5085L

//
// MessageId: ERROR_QUORUM_DISK_NOT_FOUND
//
// MessageText:
//
// The quorum disk could not be located by the cluster service.
//
#define ERROR_QUORUM_DISK_NOT_FOUND      5086L

//
// MessageId: ERROR_DATABASE_BACKUP_CORRUPT
//
// MessageText:
//
// The backed up cluster database is possibly corrupt.
//
#define ERROR_DATABASE_BACKUP_CORRUPT    5087L

//
// MessageId: ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT
//
// MessageText:
//
// A DFS root already exists in this cluster node.
//
#define ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT 5088L

//
// MessageId: ERROR_RESOURCE_PROPERTY_UNCHANGEABLE
//
// MessageText:
//
// An attempt to modify a resource property failed because it conflicts with another existing property.
//
#define ERROR_RESOURCE_PROPERTY_UNCHANGEABLE 5089L

/*
 Codes from 4300 through 5889 overlap with codes in ds\published\inc\apperr2.w.
 Do not add any more error codes in that range.
*/
//
// MessageId: ERROR_CLUSTER_MEMBERSHIP_INVALID_STATE
//
// MessageText:
//
// An operation was attempted that is incompatible with the current membership state of the node.
//
#define ERROR_CLUSTER_MEMBERSHIP_INVALID_STATE 5890L

//
// MessageId: ERROR_CLUSTER_QUORUMLOG_NOT_FOUND
//
// MessageText:
//
// The quorum resource does not contain the quorum log.
//
#define ERROR_CLUSTER_QUORUMLOG_NOT_FOUND 5891L

//
// MessageId: ERROR_CLUSTER_MEMBERSHIP_HALT
//
// MessageText:
//
// The membership engine requested shutdown of the cluster service on this node.
//
#define ERROR_CLUSTER_MEMBERSHIP_HALT    5892L

//
// MessageId: ERROR_CLUSTER_INSTANCE_ID_MISMATCH
//
// MessageText:
//
// The join operation failed because the cluster instance ID of the joining node does not match the cluster instance ID of the sponsor node.
//
#define ERROR_CLUSTER_INSTANCE_ID_MISMATCH 5893L

//
// MessageId: ERROR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP
//
// MessageText:
//
// A matching cluster network for the specified IP address could not be found.
//
#define ERROR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP 5894L

//
// MessageId: ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH
//
// MessageText:
//
// The actual data type of the property did not match the expected data type of the property.
//
#define ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH 5895L

//
// MessageId: ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP
//
// MessageText:
//
// The cluster node was evicted from the cluster successfully, but the node was not cleaned up. To determine what cleanup steps failed and how to recover, see the Failover Clustering application event log using Event Viewer.
//
#define ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP 5896L

//
// MessageId: ERROR_CLUSTER_PARAMETER_MISMATCH
//
// MessageText:
//
// Two or more parameter values specified for a resource's properties are in conflict.
//
#define ERROR_CLUSTER_PARAMETER_MISMATCH 5897L

//
// MessageId: ERROR_NODE_CANNOT_BE_CLUSTERED
//
// MessageText:
//
// This computer cannot be made a member of a cluster.
//
#define ERROR_NODE_CANNOT_BE_CLUSTERED   5898L

//
// MessageId: ERROR_CLUSTER_WRONG_OS_VERSION
//
// MessageText:
//
// This computer cannot be made a member of a cluster because it does not have the correct version of Windows installed.
//
#define ERROR_CLUSTER_WRONG_OS_VERSION   5899L

//
// MessageId: ERROR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME
//
// MessageText:
//
// A cluster cannot be created with the specified cluster name because that cluster name is already in use. Specify a different name for the cluster.
//
#define ERROR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME 5900L

//
// MessageId: ERROR_CLUSCFG_ALREADY_COMMITTED
//
// MessageText:
//
// The cluster configuration action has already been committed.
//
#define ERROR_CLUSCFG_ALREADY_COMMITTED  5901L

//
// MessageId: ERROR_CLUSCFG_ROLLBACK_FAILED
//
// MessageText:
//
// The cluster configuration action could not be rolled back.
//
#define ERROR_CLUSCFG_ROLLBACK_FAILED    5902L

//
// MessageId: ERROR_CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT
//
// MessageText:
//
// The drive letter assigned to a system disk on one node conflicted with the drive letter assigned to a disk on another node.
//
#define ERROR_CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT 5903L

//
// MessageId: ERROR_CLUSTER_OLD_VERSION
//
// MessageText:
//
// One or more nodes in the cluster are running a version of Windows that does not support this operation.
//
#define ERROR_CLUSTER_OLD_VERSION        5904L

//
// MessageId: ERROR_CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME
//
// MessageText:
//
// The name of the corresponding computer account doesn't match the Network Name for this resource.
//
#define ERROR_CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME 5905L

//
// MessageId: ERROR_CLUSTER_NO_NET_ADAPTERS
//
// MessageText:
//
// No network adapters are available.
//
#define ERROR_CLUSTER_NO_NET_ADAPTERS    5906L

//
// MessageId: ERROR_CLUSTER_POISONED
//
// MessageText:
//
// The cluster node has been poisoned.
//
#define ERROR_CLUSTER_POISONED           5907L

//
// MessageId: ERROR_CLUSTER_GROUP_MOVING
//
// MessageText:
//
// The group is unable to accept the request since it is moving to another node.
//
#define ERROR_CLUSTER_GROUP_MOVING       5908L

//
// MessageId: ERROR_CLUSTER_RESOURCE_TYPE_BUSY
//
// MessageText:
//
// The resource type cannot accept the request since is too busy performing another operation.
//
#define ERROR_CLUSTER_RESOURCE_TYPE_BUSY 5909L

//
// MessageId: ERROR_RESOURCE_CALL_TIMED_OUT
//
// MessageText:
//
// The call to the cluster resource DLL timed out.
//
#define ERROR_RESOURCE_CALL_TIMED_OUT    5910L

//
// MessageId: ERROR_INVALID_CLUSTER_IPV6_ADDRESS
//
// MessageText:
//
// The address is not valid for an IPv6 Address resource. A global IPv6 address is required, and it must match a cluster network. Compatibility addresses are not permitted.
//
#define ERROR_INVALID_CLUSTER_IPV6_ADDRESS 5911L

//
// MessageId: ERROR_CLUSTER_INTERNAL_INVALID_FUNCTION
//
// MessageText:
//
// An internal cluster error occurred. A call to an invalid function was attempted.
//
#define ERROR_CLUSTER_INTERNAL_INVALID_FUNCTION 5912L

//
// MessageId: ERROR_CLUSTER_PARAMETER_OUT_OF_BOUNDS
//
// MessageText:
//
// A parameter value is out of acceptable range.
//
#define ERROR_CLUSTER_PARAMETER_OUT_OF_BOUNDS 5913L

//
// MessageId: ERROR_CLUSTER_PARTIAL_SEND
//
// MessageText:
//
// A network error occurred while sending data to another node in the cluster. The number of bytes transmitted was less than required.
//
#define ERROR_CLUSTER_PARTIAL_SEND       5914L

//
// MessageId: ERROR_CLUSTER_REGISTRY_INVALID_FUNCTION
//
// MessageText:
//
// An invalid cluster registry operation was attempted.
//
#define ERROR_CLUSTER_REGISTRY_INVALID_FUNCTION 5915L

//
// MessageId: ERROR_CLUSTER_INVALID_STRING_TERMINATION
//
// MessageText:
//
// An input string of characters is not properly terminated.
//
#define ERROR_CLUSTER_INVALID_STRING_TERMINATION 5916L

//
// MessageId: ERROR_CLUSTER_INVALID_STRING_FORMAT
//
// MessageText:
//
// An input string of characters is not in a valid format for the data it represents.
//
#define ERROR_CLUSTER_INVALID_STRING_FORMAT 5917L

//
// MessageId: ERROR_CLUSTER_DATABASE_TRANSACTION_IN_PROGRESS
//
// MessageText:
//
// An internal cluster error occurred. A cluster database transaction was attempted while a transaction was already in progress.
//
#define ERROR_CLUSTER_DATABASE_TRANSACTION_IN_PROGRESS 5918L

//
// MessageId: ERROR_CLUSTER_DATABASE_TRANSACTION_NOT_IN_PROGRESS
//
// MessageText:
//
// An internal cluster error occurred. There was an attempt to commit a cluster database transaction while no transaction was in progress.
//
#define ERROR_CLUSTER_DATABASE_TRANSACTION_NOT_IN_PROGRESS 5919L

//
// MessageId: ERROR_CLUSTER_NULL_DATA
//
// MessageText:
//
// An internal cluster error occurred. Data was not properly initialized.
//
#define ERROR_CLUSTER_NULL_DATA          5920L

//
// MessageId: ERROR_CLUSTER_PARTIAL_READ
//
// MessageText:
//
// An error occurred while reading from a stream of data. An unexpected number of bytes was returned.
//
#define ERROR_CLUSTER_PARTIAL_READ       5921L

//
// MessageId: ERROR_CLUSTER_PARTIAL_WRITE
//
// MessageText:
//
// An error occurred while writing to a stream of data. The required number of bytes could not be written.
//
#define ERROR_CLUSTER_PARTIAL_WRITE      5922L

//
// MessageId: ERROR_CLUSTER_CANT_DESERIALIZE_DATA
//
// MessageText:
//
// An error occurred while deserializing a stream of cluster data.
//
#define ERROR_CLUSTER_CANT_DESERIALIZE_DATA 5923L

//
// MessageId: ERROR_DEPENDENT_RESOURCE_PROPERTY_CONFLICT
//
// MessageText:
//
// One or more property values for this resource are in conflict with one or more property values associated with its dependent resource(s).
//
#define ERROR_DEPENDENT_RESOURCE_PROPERTY_CONFLICT 5924L

//
// MessageId: ERROR_CLUSTER_NO_QUORUM
//
// MessageText:
//
// A quorum of cluster nodes was not present to form a cluster.
//
#define ERROR_CLUSTER_NO_QUORUM          5925L

//
// MessageId: ERROR_CLUSTER_INVALID_IPV6_NETWORK
//
// MessageText:
//
// The cluster network is not valid for an IPv6 Address resource, or it does not match the configured address.
//
#define ERROR_CLUSTER_INVALID_IPV6_NETWORK 5926L

//
// MessageId: ERROR_CLUSTER_INVALID_IPV6_TUNNEL_NETWORK
//
// MessageText:
//
// The cluster network is not valid for an IPv6 Tunnel resource. Check the configuration of the IP Address resource on which the IPv6 Tunnel resource depends.
//
#define ERROR_CLUSTER_INVALID_IPV6_TUNNEL_NETWORK 5927L

//
// MessageId: ERROR_QUORUM_NOT_ALLOWED_IN_THIS_GROUP
//
// MessageText:
//
// Quorum resource cannot reside in the Available Storage group.
//
#define ERROR_QUORUM_NOT_ALLOWED_IN_THIS_GROUP 5928L

//
// MessageId: ERROR_DEPENDENCY_TREE_TOO_COMPLEX
//
// MessageText:
//
// The dependencies for this resource are nested too deeply.
//
#define ERROR_DEPENDENCY_TREE_TOO_COMPLEX 5929L

//
// MessageId: ERROR_EXCEPTION_IN_RESOURCE_CALL
//
// MessageText:
//
// The call into the resource DLL raised an unhandled exception.
//
#define ERROR_EXCEPTION_IN_RESOURCE_CALL 5930L

//
// MessageId: ERROR_CLUSTER_RHS_FAILED_INITIALIZATION
//
// MessageText:
//
// The RHS process failed to initialize.
//
#define ERROR_CLUSTER_RHS_FAILED_INITIALIZATION 5931L

//
// MessageId: ERROR_CLUSTER_NOT_INSTALLED
//
// MessageText:
//
// The Failover Clustering feature is not installed on this node.
//
#define ERROR_CLUSTER_NOT_INSTALLED      5932L

//
// MessageId: ERROR_CLUSTER_RESOURCES_MUST_BE_ONLINE_ON_THE_SAME_NODE
//
// MessageText:
//
// The resources must be online on the same node for this operation
//
#define ERROR_CLUSTER_RESOURCES_MUST_BE_ONLINE_ON_THE_SAME_NODE 5933L

//
// MessageId: ERROR_CLUSTER_MAX_NODES_IN_CLUSTER
//
// MessageText:
//
// A new node can not be added since this cluster is already at its maximum number of nodes.
//
#define ERROR_CLUSTER_MAX_NODES_IN_CLUSTER 5934L

//
// MessageId: ERROR_CLUSTER_TOO_MANY_NODES
//
// MessageText:
//
// This cluster can not be created since the specified number of nodes exceeds the maximum allowed limit.
//
#define ERROR_CLUSTER_TOO_MANY_NODES     5935L

//
// MessageId: ERROR_CLUSTER_OBJECT_ALREADY_USED
//
// MessageText:
//
// An attempt to use the specified cluster name failed because an enabled computer object with the given name already exists in the domain
//
#define ERROR_CLUSTER_OBJECT_ALREADY_USED 5936L

//
// MessageId: ERROR_NONCORE_GROUPS_FOUND
//
// MessageText:
//
// This cluster cannot be destroyed. It has non-core application groups which must be deleted before the cluster can be destroyed.
//
#define ERROR_NONCORE_GROUPS_FOUND       5937L

//
// MessageId: ERROR_FILE_SHARE_RESOURCE_CONFLICT
//
// MessageText:
//
// File share associated with file share witness resource cannot be hosted by this cluster or any of its nodes.
//
#define ERROR_FILE_SHARE_RESOURCE_CONFLICT 5938L

//
// MessageId: ERROR_CLUSTER_EVICT_INVALID_REQUEST
//
// MessageText:
//
// The last node in the cluster can not evicted especially when the cluster contains one or more active cluster resources.
//
#define ERROR_CLUSTER_EVICT_INVALID_REQUEST 5939L


///////////////////////////////////////////////////
//                                               //
//               EFS Error codes                 //
//                                               //
//                 6000 to 6099                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_ENCRYPTION_FAILED
//
// MessageText:
//
// The specified file could not be encrypted.
//
#define ERROR_ENCRYPTION_FAILED          6000L

//
// MessageId: ERROR_DECRYPTION_FAILED
//
// MessageText:
//
// The specified file could not be decrypted.
//
#define ERROR_DECRYPTION_FAILED          6001L

//
// MessageId: ERROR_FILE_ENCRYPTED
//
// MessageText:
//
// The specified file is encrypted and the user does not have the ability to decrypt it.
//
#define ERROR_FILE_ENCRYPTED             6002L

//
// MessageId: ERROR_NO_RECOVERY_POLICY
//
// MessageText:
//
// There is no valid encryption recovery policy configured for this system.
//
#define ERROR_NO_RECOVERY_POLICY         6003L

//
// MessageId: ERROR_NO_EFS
//
// MessageText:
//
// The required encryption driver is not loaded for this system.
//
#define ERROR_NO_EFS                     6004L

//
// MessageId: ERROR_WRONG_EFS
//
// MessageText:
//
// The file was encrypted with a different encryption driver than is currently loaded.
//
#define ERROR_WRONG_EFS                  6005L

//
// MessageId: ERROR_NO_USER_KEYS
//
// MessageText:
//
// There are no EFS keys defined for the user.
//
#define ERROR_NO_USER_KEYS               6006L

//
// MessageId: ERROR_FILE_NOT_ENCRYPTED
//
// MessageText:
//
// The specified file is not encrypted.
//
#define ERROR_FILE_NOT_ENCRYPTED         6007L

//
// MessageId: ERROR_NOT_EXPORT_FORMAT
//
// MessageText:
//
// The specified file is not in the defined EFS export format.
//
#define ERROR_NOT_EXPORT_FORMAT          6008L

//
// MessageId: ERROR_FILE_READ_ONLY
//
// MessageText:
//
// The specified file is read only.
//
#define ERROR_FILE_READ_ONLY             6009L

//
// MessageId: ERROR_DIR_EFS_DISALLOWED
//
// MessageText:
//
// The directory has been disabled for encryption.
//
#define ERROR_DIR_EFS_DISALLOWED         6010L

//
// MessageId: ERROR_EFS_SERVER_NOT_TRUSTED
//
// MessageText:
//
// The server is not trusted for remote encryption operation.
//
#define ERROR_EFS_SERVER_NOT_TRUSTED     6011L

//
// MessageId: ERROR_BAD_RECOVERY_POLICY
//
// MessageText:
//
// Recovery policy configured for this system contains invalid recovery certificate.
//
#define ERROR_BAD_RECOVERY_POLICY        6012L

//
// MessageId: ERROR_EFS_ALG_BLOB_TOO_BIG
//
// MessageText:
//
// The encryption algorithm used on the source file needs a bigger key buffer than the one on the destination file.
//
#define ERROR_EFS_ALG_BLOB_TOO_BIG       6013L

//
// MessageId: ERROR_VOLUME_NOT_SUPPORT_EFS
//
// MessageText:
//
// The disk partition does not support file encryption.
//
#define ERROR_VOLUME_NOT_SUPPORT_EFS     6014L

//
// MessageId: ERROR_EFS_DISABLED
//
// MessageText:
//
// This machine is disabled for file encryption.
//
#define ERROR_EFS_DISABLED               6015L

//
// MessageId: ERROR_EFS_VERSION_NOT_SUPPORT
//
// MessageText:
//
// A newer system is required to decrypt this encrypted file.
//
#define ERROR_EFS_VERSION_NOT_SUPPORT    6016L

//
// MessageId: ERROR_CS_ENCRYPTION_INVALID_SERVER_RESPONSE
//
// MessageText:
//
// The remote server sent an invalid response for a file being opened with Client Side Encryption.
//
#define ERROR_CS_ENCRYPTION_INVALID_SERVER_RESPONSE 6017L

//
// MessageId: ERROR_CS_ENCRYPTION_UNSUPPORTED_SERVER
//
// MessageText:
//
// Client Side Encryption is not supported by the remote server even though it claims to support it.
//
#define ERROR_CS_ENCRYPTION_UNSUPPORTED_SERVER 6018L

//
// MessageId: ERROR_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE
//
// MessageText:
//
// File is encrypted and should be opened in Client Side Encryption mode.
//
#define ERROR_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE 6019L

//
// MessageId: ERROR_CS_ENCRYPTION_NEW_ENCRYPTED_FILE
//
// MessageText:
//
// A new encrypted file is being created and a $EFS needs to be provided.
//
#define ERROR_CS_ENCRYPTION_NEW_ENCRYPTED_FILE 6020L

//
// MessageId: ERROR_CS_ENCRYPTION_FILE_NOT_CSE
//
// MessageText:
//
// The SMB client requested a CSE FSCTL on a non-CSE file.
//
#define ERROR_CS_ENCRYPTION_FILE_NOT_CSE 6021L


///////////////////////////////////////////////////
//                                               //
//              BROWSER Error codes              //
//                                               //
//                 6100 to 6199                  //
///////////////////////////////////////////////////

// This message number is for historical purposes and cannot be changed or re-used.
//
// MessageId: ERROR_NO_BROWSER_SERVERS_FOUND
//
// MessageText:
//
// The list of servers for this workgroup is not currently available
//
#define ERROR_NO_BROWSER_SERVERS_FOUND   6118L


///////////////////////////////////////////////////
//                                               //
//            Task Scheduler Error codes         //
//            NET START must understand          //
//                                               //
//                 6200 to 6249                  //
///////////////////////////////////////////////////

//
// MessageId: SCHED_E_SERVICE_NOT_LOCALSYSTEM
//
// MessageText:
//
// The Task Scheduler service must be configured to run in the System account to function properly. Individual tasks may be configured to run in other accounts.
//
#define SCHED_E_SERVICE_NOT_LOCALSYSTEM  6200L


///////////////////////////////////////////////////
//                                               //
//                  Available                    //
//                                               //
//                 6250 to 6599                  //
///////////////////////////////////////////////////

///////////////////////////////////////////////////
//                                               //
//         Common Log (CLFS) Error codes         //
//                                               //
//                 6600 to 6699                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_LOG_SECTOR_INVALID
//
// MessageText:
//
// Log service encountered an invalid log sector.
//
#define ERROR_LOG_SECTOR_INVALID         6600L

//
// MessageId: ERROR_LOG_SECTOR_PARITY_INVALID
//
// MessageText:
//
// Log service encountered a log sector with invalid block parity.
//
#define ERROR_LOG_SECTOR_PARITY_INVALID  6601L

//
// MessageId: ERROR_LOG_SECTOR_REMAPPED
//
// MessageText:
//
// Log service encountered a remapped log sector.
//
#define ERROR_LOG_SECTOR_REMAPPED        6602L

//
// MessageId: ERROR_LOG_BLOCK_INCOMPLETE
//
// MessageText:
//
// Log service encountered a partial or incomplete log block.
//
#define ERROR_LOG_BLOCK_INCOMPLETE       6603L

//
// MessageId: ERROR_LOG_INVALID_RANGE
//
// MessageText:
//
// Log service encountered an attempt access data outside the active log range.
//
#define ERROR_LOG_INVALID_RANGE          6604L

//
// MessageId: ERROR_LOG_BLOCKS_EXHAUSTED
//
// MessageText:
//
// Log service user marshalling buffers are exhausted.
//
#define ERROR_LOG_BLOCKS_EXHAUSTED       6605L

//
// MessageId: ERROR_LOG_READ_CONTEXT_INVALID
//
// MessageText:
//
// Log service encountered an attempt read from a marshalling area with an invalid read context.
//
#define ERROR_LOG_READ_CONTEXT_INVALID   6606L

//
// MessageId: ERROR_LOG_RESTART_INVALID
//
// MessageText:
//
// Log service encountered an invalid log restart area.
//
#define ERROR_LOG_RESTART_INVALID        6607L

//
// MessageId: ERROR_LOG_BLOCK_VERSION
//
// MessageText:
//
// Log service encountered an invalid log block version.
//
#define ERROR_LOG_BLOCK_VERSION          6608L

//
// MessageId: ERROR_LOG_BLOCK_INVALID
//
// MessageText:
//
// Log service encountered an invalid log block.
//
#define ERROR_LOG_BLOCK_INVALID          6609L

//
// MessageId: ERROR_LOG_READ_MODE_INVALID
//
// MessageText:
//
// Log service encountered an attempt to read the log with an invalid read mode.
//
#define ERROR_LOG_READ_MODE_INVALID      6610L

//
// MessageId: ERROR_LOG_NO_RESTART
//
// MessageText:
//
// Log service encountered a log stream with no restart area.
//
#define ERROR_LOG_NO_RESTART             6611L

//
// MessageId: ERROR_LOG_METADATA_CORRUPT
//
// MessageText:
//
// Log service encountered a corrupted metadata file.
//
#define ERROR_LOG_METADATA_CORRUPT       6612L

//
// MessageId: ERROR_LOG_METADATA_INVALID
//
// MessageText:
//
// Log service encountered a metadata file that could not be created by the log file system.
//
#define ERROR_LOG_METADATA_INVALID       6613L

//
// MessageId: ERROR_LOG_METADATA_INCONSISTENT
//
// MessageText:
//
// Log service encountered a metadata file with inconsistent data.
//
#define ERROR_LOG_METADATA_INCONSISTENT  6614L

//
// MessageId: ERROR_LOG_RESERVATION_INVALID
//
// MessageText:
//
// Log service encountered an attempt to erroneous allocate or dispose reservation space.
//
#define ERROR_LOG_RESERVATION_INVALID    6615L

//
// MessageId: ERROR_LOG_CANT_DELETE
//
// MessageText:
//
// Log service cannot delete log file or file system container.
//
#define ERROR_LOG_CANT_DELETE            6616L

//
// MessageId: ERROR_LOG_CONTAINER_LIMIT_EXCEEDED
//
// MessageText:
//
// Log service has reached the maximum allowable containers allocated to a log file.
//
#define ERROR_LOG_CONTAINER_LIMIT_EXCEEDED 6617L

//
// MessageId: ERROR_LOG_START_OF_LOG
//
// MessageText:
//
// Log service has attempted to read or write backward past the start of the log.
//
#define ERROR_LOG_START_OF_LOG           6618L

//
// MessageId: ERROR_LOG_POLICY_ALREADY_INSTALLED
//
// MessageText:
//
// Log policy could not be installed because a policy of the same type is already present.
//
#define ERROR_LOG_POLICY_ALREADY_INSTALLED 6619L

//
// MessageId: ERROR_LOG_POLICY_NOT_INSTALLED
//
// MessageText:
//
// Log policy in question was not installed at the time of the request.
//
#define ERROR_LOG_POLICY_NOT_INSTALLED   6620L

//
// MessageId: ERROR_LOG_POLICY_INVALID
//
// MessageText:
//
// The installed set of policies on the log is invalid.
//
#define ERROR_LOG_POLICY_INVALID         6621L

//
// MessageId: ERROR_LOG_POLICY_CONFLICT
//
// MessageText:
//
// A policy on the log in question prevented the operation from completing.
//
#define ERROR_LOG_POLICY_CONFLICT        6622L

//
// MessageId: ERROR_LOG_PINNED_ARCHIVE_TAIL
//
// MessageText:
//
// Log space cannot be reclaimed because the log is pinned by the archive tail.
//
#define ERROR_LOG_PINNED_ARCHIVE_TAIL    6623L

//
// MessageId: ERROR_LOG_RECORD_NONEXISTENT
//
// MessageText:
//
// Log record is not a record in the log file.
//
#define ERROR_LOG_RECORD_NONEXISTENT     6624L

//
// MessageId: ERROR_LOG_RECORDS_RESERVED_INVALID
//
// MessageText:
//
// Number of reserved log records or the adjustment of the number of reserved log records is invalid.
//
#define ERROR_LOG_RECORDS_RESERVED_INVALID 6625L

//
// MessageId: ERROR_LOG_SPACE_RESERVED_INVALID
//
// MessageText:
//
// Reserved log space or the adjustment of the log space is invalid.
//
#define ERROR_LOG_SPACE_RESERVED_INVALID 6626L

//
// MessageId: ERROR_LOG_TAIL_INVALID
//
// MessageText:
//
// An new or existing archive tail or base of the active log is invalid.
//
#define ERROR_LOG_TAIL_INVALID           6627L

//
// MessageId: ERROR_LOG_FULL
//
// MessageText:
//
// Log space is exhausted.
//
#define ERROR_LOG_FULL                   6628L

//
// MessageId: ERROR_COULD_NOT_RESIZE_LOG
//
// MessageText:
//
// The log could not be set to the requested size.
//
#define ERROR_COULD_NOT_RESIZE_LOG       6629L

//
// MessageId: ERROR_LOG_MULTIPLEXED
//
// MessageText:
//
// Log is multiplexed, no direct writes to the physical log is allowed.
//
#define ERROR_LOG_MULTIPLEXED            6630L

//
// MessageId: ERROR_LOG_DEDICATED
//
// MessageText:
//
// The operation failed because the log is a dedicated log.
//
#define ERROR_LOG_DEDICATED              6631L

//
// MessageId: ERROR_LOG_ARCHIVE_NOT_IN_PROGRESS
//
// MessageText:
//
// The operation requires an archive context.
//
#define ERROR_LOG_ARCHIVE_NOT_IN_PROGRESS 6632L

//
// MessageId: ERROR_LOG_ARCHIVE_IN_PROGRESS
//
// MessageText:
//
// Log archival is in progress.
//
#define ERROR_LOG_ARCHIVE_IN_PROGRESS    6633L

//
// MessageId: ERROR_LOG_EPHEMERAL
//
// MessageText:
//
// The operation requires a non-ephemeral log, but the log is ephemeral.
//
#define ERROR_LOG_EPHEMERAL              6634L

//
// MessageId: ERROR_LOG_NOT_ENOUGH_CONTAINERS
//
// MessageText:
//
// The log must have at least two containers before it can be read from or written to.
//
#define ERROR_LOG_NOT_ENOUGH_CONTAINERS  6635L

//
// MessageId: ERROR_LOG_CLIENT_ALREADY_REGISTERED
//
// MessageText:
//
// A log client has already registered on the stream.
//
#define ERROR_LOG_CLIENT_ALREADY_REGISTERED 6636L

//
// MessageId: ERROR_LOG_CLIENT_NOT_REGISTERED
//
// MessageText:
//
// A log client has not been registered on the stream.
//
#define ERROR_LOG_CLIENT_NOT_REGISTERED  6637L

//
// MessageId: ERROR_LOG_FULL_HANDLER_IN_PROGRESS
//
// MessageText:
//
// A request has already been made to handle the log full condition.
//
#define ERROR_LOG_FULL_HANDLER_IN_PROGRESS 6638L

//
// MessageId: ERROR_LOG_CONTAINER_READ_FAILED
//
// MessageText:
//
// Log service enountered an error when attempting to read from a log container.
//
#define ERROR_LOG_CONTAINER_READ_FAILED  6639L

//
// MessageId: ERROR_LOG_CONTAINER_WRITE_FAILED
//
// MessageText:
//
// Log service enountered an error when attempting to write to a log container.
//
#define ERROR_LOG_CONTAINER_WRITE_FAILED 6640L

//
// MessageId: ERROR_LOG_CONTAINER_OPEN_FAILED
//
// MessageText:
//
// Log service enountered an error when attempting open a log container.
//
#define ERROR_LOG_CONTAINER_OPEN_FAILED  6641L

//
// MessageId: ERROR_LOG_CONTAINER_STATE_INVALID
//
// MessageText:
//
// Log service enountered an invalid container state when attempting a requested action.
//
#define ERROR_LOG_CONTAINER_STATE_INVALID 6642L

//
// MessageId: ERROR_LOG_STATE_INVALID
//
// MessageText:
//
// Log service is not in the correct state to perform a requested action.
//
#define ERROR_LOG_STATE_INVALID          6643L

//
// MessageId: ERROR_LOG_PINNED
//
// MessageText:
//
// Log space cannot be reclaimed because the log is pinned.
//
#define ERROR_LOG_PINNED                 6644L

//
// MessageId: ERROR_LOG_METADATA_FLUSH_FAILED
//
// MessageText:
//
// Log metadata flush failed.
//
#define ERROR_LOG_METADATA_FLUSH_FAILED  6645L

//
// MessageId: ERROR_LOG_INCONSISTENT_SECURITY
//
// MessageText:
//
// Security on the log and its containers is inconsistent.
//
#define ERROR_LOG_INCONSISTENT_SECURITY  6646L

//
// MessageId: ERROR_LOG_APPENDED_FLUSH_FAILED
//
// MessageText:
//
// Records were appended to the log or reservation changes were made, but the log could not be flushed.
//
#define ERROR_LOG_APPENDED_FLUSH_FAILED  6647L

//
// MessageId: ERROR_LOG_PINNED_RESERVATION
//
// MessageText:
//
// The log is pinned due to reservation consuming most of the log space. Free some reserved records to make space available.
//
#define ERROR_LOG_PINNED_RESERVATION     6648L


///////////////////////////////////////////////////
//                                               //
//           Transaction (KTM) Error codes       //
//                                               //
//                 6700 to 6799                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_INVALID_TRANSACTION
//
// MessageText:
//
// The transaction handle associated with this operation is not valid.
//
#define ERROR_INVALID_TRANSACTION        6700L

//
// MessageId: ERROR_TRANSACTION_NOT_ACTIVE
//
// MessageText:
//
// The requested operation was made in the context of a transaction that is no longer active.
//
#define ERROR_TRANSACTION_NOT_ACTIVE     6701L

//
// MessageId: ERROR_TRANSACTION_REQUEST_NOT_VALID
//
// MessageText:
//
// The requested operation is not valid on the Transaction object in its current state.
//
#define ERROR_TRANSACTION_REQUEST_NOT_VALID 6702L

//
// MessageId: ERROR_TRANSACTION_NOT_REQUESTED
//
// MessageText:
//
// The caller has called a response API, but the response is not expected because the TM did not issue the corresponding request to the caller.
//
#define ERROR_TRANSACTION_NOT_REQUESTED  6703L

//
// MessageId: ERROR_TRANSACTION_ALREADY_ABORTED
//
// MessageText:
//
// It is too late to perform the requested operation, since the Transaction has already been aborted.
//
#define ERROR_TRANSACTION_ALREADY_ABORTED 6704L

//
// MessageId: ERROR_TRANSACTION_ALREADY_COMMITTED
//
// MessageText:
//
// It is too late to perform the requested operation, since the Transaction has already been committed.
//
#define ERROR_TRANSACTION_ALREADY_COMMITTED 6705L

//
// MessageId: ERROR_TM_INITIALIZATION_FAILED
//
// MessageText:
//
// The Transaction Manager was unable to be successfully initialized. Transacted operations are not supported.
//
#define ERROR_TM_INITIALIZATION_FAILED   6706L

//
// MessageId: ERROR_RESOURCEMANAGER_READ_ONLY
//
// MessageText:
//
// The specified ResourceManager made no changes or updates to the resource under this transaction.
//
#define ERROR_RESOURCEMANAGER_READ_ONLY  6707L

//
// MessageId: ERROR_TRANSACTION_NOT_JOINED
//
// MessageText:
//
// The resource manager has attempted to prepare a transaction that it has not successfully joined.
//
#define ERROR_TRANSACTION_NOT_JOINED     6708L

//
// MessageId: ERROR_TRANSACTION_SUPERIOR_EXISTS
//
// MessageText:
//
// The Transaction object already has a superior enlistment, and the caller attempted an operation that would have created a new superior. Only a single superior enlistment is allow.
//
#define ERROR_TRANSACTION_SUPERIOR_EXISTS 6709L

//
// MessageId: ERROR_CRM_PROTOCOL_ALREADY_EXISTS
//
// MessageText:
//
// The RM tried to register a protocol that already exists.
//
#define ERROR_CRM_PROTOCOL_ALREADY_EXISTS 6710L

//
// MessageId: ERROR_TRANSACTION_PROPAGATION_FAILED
//
// MessageText:
//
// The attempt to propagate the Transaction failed.
//
#define ERROR_TRANSACTION_PROPAGATION_FAILED 6711L

//
// MessageId: ERROR_CRM_PROTOCOL_NOT_FOUND
//
// MessageText:
//
// The requested propagation protocol was not registered as a CRM.
//
#define ERROR_CRM_PROTOCOL_NOT_FOUND     6712L

//
// MessageId: ERROR_TRANSACTION_INVALID_MARSHALL_BUFFER
//
// MessageText:
//
// The buffer passed in to PushTransaction or PullTransaction is not in a valid format.
//
#define ERROR_TRANSACTION_INVALID_MARSHALL_BUFFER 6713L

//
// MessageId: ERROR_CURRENT_TRANSACTION_NOT_VALID
//
// MessageText:
//
// The current transaction context associated with the thread is not a valid handle to a transaction object.
//
#define ERROR_CURRENT_TRANSACTION_NOT_VALID 6714L

//
// MessageId: ERROR_TRANSACTION_NOT_FOUND
//
// MessageText:
//
// The specified Transaction object could not be opened, because it was not found.
//
#define ERROR_TRANSACTION_NOT_FOUND      6715L

//
// MessageId: ERROR_RESOURCEMANAGER_NOT_FOUND
//
// MessageText:
//
// The specified ResourceManager object could not be opened, because it was not found.
//
#define ERROR_RESOURCEMANAGER_NOT_FOUND  6716L

//
// MessageId: ERROR_ENLISTMENT_NOT_FOUND
//
// MessageText:
//
// The specified Enlistment object could not be opened, because it was not found.
//
#define ERROR_ENLISTMENT_NOT_FOUND       6717L

//
// MessageId: ERROR_TRANSACTIONMANAGER_NOT_FOUND
//
// MessageText:
//
// The specified TransactionManager object could not be opened, because it was not found.
//
#define ERROR_TRANSACTIONMANAGER_NOT_FOUND 6718L

//
// MessageId: ERROR_TRANSACTIONMANAGER_NOT_ONLINE
//
// MessageText:
//
// The specified ResourceManager was unable to create an enlistment, because its associated TransactionManager is not online.
//
#define ERROR_TRANSACTIONMANAGER_NOT_ONLINE 6719L

//
// MessageId: ERROR_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION
//
// MessageText:
//
// The specified TransactionManager was unable to create the objects contained in its logfile in the Ob namespace. Therefore, the TransactionManager was unable to recover.
//
#define ERROR_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION 6720L

//
// MessageId: ERROR_TRANSACTION_NOT_ROOT
//
// MessageText:
//
// The call to create a superior Enlistment on this Transaction object could not be completed, because the Transaction object specified for the enlistment is a subordinate branch of the Transaction.  Only the root of the Transactoin can be enlisted on as a superior.
//
#define ERROR_TRANSACTION_NOT_ROOT       6721L

//
// MessageId: ERROR_TRANSACTION_OBJECT_EXPIRED
//
// MessageText:
//
// Because the associated transaction manager or resource manager has been closed, the handle is no longer valid.
//
#define ERROR_TRANSACTION_OBJECT_EXPIRED 6722L

//
// MessageId: ERROR_TRANSACTION_RESPONSE_NOT_ENLISTED
//
// MessageText:
//
// The specified operation could not be performed on this Superior enlistment, because the enlistment was not created with the corresponding completion response in the NotificationMask.
//
#define ERROR_TRANSACTION_RESPONSE_NOT_ENLISTED 6723L

//
// MessageId: ERROR_TRANSACTION_RECORD_TOO_LONG
//
// MessageText:
//
// The specified operation could not be performed, because the record that would be logged was too long.  This can occur because of two conditions:  either there are too many Enlistments on this Transaction, or the combined RecoveryInformation being logged on behalf of those Enlistments is too long.
//
#define ERROR_TRANSACTION_RECORD_TOO_LONG 6724L

//
// MessageId: ERROR_IMPLICIT_TRANSACTION_NOT_SUPPORTED
//
// MessageText:
//
// Implicit transaction are not supported.
//
#define ERROR_IMPLICIT_TRANSACTION_NOT_SUPPORTED 6725L

//
// MessageId: ERROR_TRANSACTION_INTEGRITY_VIOLATED
//
// MessageText:
//
// The kernel transaction manager had to abort or forget the transaction because it blocked forward progress.
//
#define ERROR_TRANSACTION_INTEGRITY_VIOLATED 6726L


///////////////////////////////////////////////////
//                                               //
//        Transactional File Services (TxF)      //
//                  Error codes                  //
//                                               //
//                 6800 to 6899                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_TRANSACTIONAL_CONFLICT
//
// MessageText:
//
// The function attempted to use a name that is reserved for use by another transaction.
//
#define ERROR_TRANSACTIONAL_CONFLICT     6800L

//
// MessageId: ERROR_RM_NOT_ACTIVE
//
// MessageText:
//
// Transaction support within the specified file system resource manager is not started or was shutdown due to an error.
//
#define ERROR_RM_NOT_ACTIVE              6801L

//
// MessageId: ERROR_RM_METADATA_CORRUPT
//
// MessageText:
//
// The metadata of the RM has been corrupted. The RM will not function.
//
#define ERROR_RM_METADATA_CORRUPT        6802L

//
// MessageId: ERROR_DIRECTORY_NOT_RM
//
// MessageText:
//
// The specified directory does not contain a resource manager.
//
#define ERROR_DIRECTORY_NOT_RM           6803L

//
// MessageId: ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE
//
// MessageText:
//
// The remote server or share does not support transacted file operations.
//
#define ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE 6805L

//
// MessageId: ERROR_LOG_RESIZE_INVALID_SIZE
//
// MessageText:
//
// The requested log size is invalid.
//
#define ERROR_LOG_RESIZE_INVALID_SIZE    6806L

//
// MessageId: ERROR_OBJECT_NO_LONGER_EXISTS
//
// MessageText:
//
// The object (file, stream, link) corresponding to the handle has been deleted by a Transaction Savepoint Rollback.
//
#define ERROR_OBJECT_NO_LONGER_EXISTS    6807L

//
// MessageId: ERROR_STREAM_MINIVERSION_NOT_FOUND
//
// MessageText:
//
// The specified file miniversion was not found for this transacted file open.
//
#define ERROR_STREAM_MINIVERSION_NOT_FOUND 6808L

//
// MessageId: ERROR_STREAM_MINIVERSION_NOT_VALID
//
// MessageText:
//
// The specified file miniversion was found but has been invalidated. Most likely cause is a transaction savepoint rollback.
//
#define ERROR_STREAM_MINIVERSION_NOT_VALID 6809L

//
// MessageId: ERROR_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION
//
// MessageText:
//
// A miniversion may only be opened in the context of the transaction that created it.
//
#define ERROR_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION 6810L

//
// MessageId: ERROR_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT
//
// MessageText:
//
// It is not possible to open a miniversion with modify access.
//
#define ERROR_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT 6811L

//
// MessageId: ERROR_CANT_CREATE_MORE_STREAM_MINIVERSIONS
//
// MessageText:
//
// It is not possible to create any more miniversions for this stream.
//
#define ERROR_CANT_CREATE_MORE_STREAM_MINIVERSIONS 6812L

//
// MessageId: ERROR_REMOTE_FILE_VERSION_MISMATCH
//
// MessageText:
//
// The remote server sent mismatching version number or Fid for a file opened with transactions.
//
#define ERROR_REMOTE_FILE_VERSION_MISMATCH 6814L

//
// MessageId: ERROR_HANDLE_NO_LONGER_VALID
//
// MessageText:
//
// The handle has been invalidated by a transaction. The most likely cause is the presence of memory mapping on a file or an open handle when the transaction ended or rolled back to savepoint.
//
#define ERROR_HANDLE_NO_LONGER_VALID     6815L

//
// MessageId: ERROR_NO_TXF_METADATA
//
// MessageText:
//
// There is no transaction metadata on the file.
//
#define ERROR_NO_TXF_METADATA            6816L

//
// MessageId: ERROR_LOG_CORRUPTION_DETECTED
//
// MessageText:
//
// The log data is corrupt.
//
#define ERROR_LOG_CORRUPTION_DETECTED    6817L

//
// MessageId: ERROR_CANT_RECOVER_WITH_HANDLE_OPEN
//
// MessageText:
//
// The file can't be recovered because there is a handle still open on it.
//
#define ERROR_CANT_RECOVER_WITH_HANDLE_OPEN 6818L

//
// MessageId: ERROR_RM_DISCONNECTED
//
// MessageText:
//
// The transaction outcome is unavailable because the resource manager responsible for it has disconnected.
//
#define ERROR_RM_DISCONNECTED            6819L

//
// MessageId: ERROR_ENLISTMENT_NOT_SUPERIOR
//
// MessageText:
//
// The request was rejected because the enlistment in question is not a superior enlistment.
//
#define ERROR_ENLISTMENT_NOT_SUPERIOR    6820L

//
// MessageId: ERROR_RECOVERY_NOT_NEEDED
//
// MessageText:
//
// The transactional resource manager is already consistent. Recovery is not needed.
//
#define ERROR_RECOVERY_NOT_NEEDED        6821L

//
// MessageId: ERROR_RM_ALREADY_STARTED
//
// MessageText:
//
// The transactional resource manager has already been started.
//
#define ERROR_RM_ALREADY_STARTED         6822L

//
// MessageId: ERROR_FILE_IDENTITY_NOT_PERSISTENT
//
// MessageText:
//
// The file cannot be opened transactionally, because its identity depends on the outcome of an unresolved transaction.
//
#define ERROR_FILE_IDENTITY_NOT_PERSISTENT 6823L

//
// MessageId: ERROR_CANT_BREAK_TRANSACTIONAL_DEPENDENCY
//
// MessageText:
//
// The operation cannot be performed because another transaction is depending on the fact that this property will not change.
//
#define ERROR_CANT_BREAK_TRANSACTIONAL_DEPENDENCY 6824L

//
// MessageId: ERROR_CANT_CROSS_RM_BOUNDARY
//
// MessageText:
//
// The operation would involve a single file with two transactional resource managers and is therefore not allowed.
//
#define ERROR_CANT_CROSS_RM_BOUNDARY     6825L

//
// MessageId: ERROR_TXF_DIR_NOT_EMPTY
//
// MessageText:
//
// The $Txf directory must be empty for this operation to succeed.
//
#define ERROR_TXF_DIR_NOT_EMPTY          6826L

//
// MessageId: ERROR_INDOUBT_TRANSACTIONS_EXIST
//
// MessageText:
//
// The operation would leave a transactional resource manager in an inconsistent state and is therefore not allowed.
//
#define ERROR_INDOUBT_TRANSACTIONS_EXIST 6827L

//
// MessageId: ERROR_TM_VOLATILE
//
// MessageText:
//
// The operation could not be completed because the transaction manager does not have a log.
//
#define ERROR_TM_VOLATILE                6828L

//
// MessageId: ERROR_ROLLBACK_TIMER_EXPIRED
//
// MessageText:
//
// A rollback could not be scheduled because a previously scheduled rollback has already executed or been queued for execution.
//
#define ERROR_ROLLBACK_TIMER_EXPIRED     6829L

//
// MessageId: ERROR_TXF_ATTRIBUTE_CORRUPT
//
// MessageText:
//
// The transactional metadata attribute on the file or directory is corrupt and unreadable.
//
#define ERROR_TXF_ATTRIBUTE_CORRUPT      6830L

//
// MessageId: ERROR_EFS_NOT_ALLOWED_IN_TRANSACTION
//
// MessageText:
//
// The encryption operation could not be completed because a transaction is active.
//
#define ERROR_EFS_NOT_ALLOWED_IN_TRANSACTION 6831L

//
// MessageId: ERROR_TRANSACTIONAL_OPEN_NOT_ALLOWED
//
// MessageText:
//
// This object is not allowed to be opened in a transaction.
//
#define ERROR_TRANSACTIONAL_OPEN_NOT_ALLOWED 6832L

//
// MessageId: ERROR_LOG_GROWTH_FAILED
//
// MessageText:
//
// An attempt to create space in the transactional resource manager's log failed. The failure status has been recorded in the event log.
//
#define ERROR_LOG_GROWTH_FAILED          6833L

//
// MessageId: ERROR_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE
//
// MessageText:
//
// Memory mapping (creating a mapped section) a remote file under a transaction is not supported.
//
#define ERROR_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE 6834L

//
// MessageId: ERROR_TXF_METADATA_ALREADY_PRESENT
//
// MessageText:
//
// Transaction metadata is already present on this file and cannot be superseded.
//
#define ERROR_TXF_METADATA_ALREADY_PRESENT 6835L

//
// MessageId: ERROR_TRANSACTION_SCOPE_CALLBACKS_NOT_SET
//
// MessageText:
//
// A transaction scope could not be entered because the scope handler has not been initialized.
//
#define ERROR_TRANSACTION_SCOPE_CALLBACKS_NOT_SET 6836L

//
// MessageId: ERROR_TRANSACTION_REQUIRED_PROMOTION
//
// MessageText:
//
// Promotion was required in order to allow the resource manager to enlist, but the transaction was set to disallow it.
//
#define ERROR_TRANSACTION_REQUIRED_PROMOTION 6837L

//
// MessageId: ERROR_CANNOT_EXECUTE_FILE_IN_TRANSACTION
//
// MessageText:
//
// This file is open for modification in an unresolved transaction and may be opened for execute only by a transacted reader.
//
#define ERROR_CANNOT_EXECUTE_FILE_IN_TRANSACTION 6838L

//
// MessageId: ERROR_TRANSACTIONS_NOT_FROZEN
//
// MessageText:
//
// The request to thaw frozen transactions was ignored because transactions had not previously been frozen.
//
#define ERROR_TRANSACTIONS_NOT_FROZEN    6839L

//
// MessageId: ERROR_TRANSACTION_FREEZE_IN_PROGRESS
//
// MessageText:
//
// Transactions cannot be frozen because a freeze is already in progress.
//
#define ERROR_TRANSACTION_FREEZE_IN_PROGRESS 6840L

//
// MessageId: ERROR_NOT_SNAPSHOT_VOLUME
//
// MessageText:
//
// The target volume is not a snapshot volume. This operation is only valid on a volume mounted as a snapshot.
//
#define ERROR_NOT_SNAPSHOT_VOLUME        6841L

//
// MessageId: ERROR_NO_SAVEPOINT_WITH_OPEN_FILES
//
// MessageText:
//
// The savepoint operation failed because files are open on the transaction. This is not permitted.
//
#define ERROR_NO_SAVEPOINT_WITH_OPEN_FILES 6842L

//
// MessageId: ERROR_DATA_LOST_REPAIR
//
// MessageText:
//
// Windows has discovered corruption in a file, and that file has since been repaired. Data loss may have occurred.
//
#define ERROR_DATA_LOST_REPAIR           6843L

//
// MessageId: ERROR_SPARSE_NOT_ALLOWED_IN_TRANSACTION
//
// MessageText:
//
// The sparse operation could not be completed because a transaction is active on the file.
//
#define ERROR_SPARSE_NOT_ALLOWED_IN_TRANSACTION 6844L

//
// MessageId: ERROR_TM_IDENTITY_MISMATCH
//
// MessageText:
//
// The call to create a TransactionManager object failed because the Tm Identity stored in the logfile does not match the Tm Identity that was passed in as an argument.
//
#define ERROR_TM_IDENTITY_MISMATCH       6845L

//
// MessageId: ERROR_FLOATED_SECTION
//
// MessageText:
//
// I/O was attempted on a section object that has been floated as a result of a transaction ending. There is no valid data.
//
#define ERROR_FLOATED_SECTION            6846L

//
// MessageId: ERROR_CANNOT_ACCEPT_TRANSACTED_WORK
//
// MessageText:
//
// The transactional resource manager cannot currently accept transacted work due to a transient condition such as low resources.
//
#define ERROR_CANNOT_ACCEPT_TRANSACTED_WORK 6847L

//
// MessageId: ERROR_CANNOT_ABORT_TRANSACTIONS
//
// MessageText:
//
// The transactional resource manager had too many tranactions outstanding that could not be aborted. The transactional resource manger has been shut down.
//
#define ERROR_CANNOT_ABORT_TRANSACTIONS  6848L

//
// MessageId: ERROR_BAD_CLUSTERS
//
// MessageText:
//
// The operation could not be completed due to bad clusters on disk.
//
#define ERROR_BAD_CLUSTERS               6849L

//
// MessageId: ERROR_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION
//
// MessageText:
//
// The compression operation could not be completed because a transaction is active on the file.
//
#define ERROR_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION 6850L

//
// MessageId: ERROR_VOLUME_DIRTY
//
// MessageText:
//
// The operation could not be completed because the volume is dirty.  Please run chkdsk and try again.
//
#define ERROR_VOLUME_DIRTY               6851L

//
// MessageId: ERROR_NO_LINK_TRACKING_IN_TRANSACTION
//
// MessageText:
//
// The link tracking operation could not be completed because a transaction is active.
//
#define ERROR_NO_LINK_TRACKING_IN_TRANSACTION 6852L

//
// MessageId: ERROR_OPERATION_NOT_SUPPORTED_IN_TRANSACTION
//
// MessageText:
//
// This operation cannot be performed in a transaction.
//
#define ERROR_OPERATION_NOT_SUPPORTED_IN_TRANSACTION 6853L


///////////////////////////////////////////////////
//                                               //
//                  Available                    //
//                                               //
//                 6900 to 6999                  //
///////////////////////////////////////////////////

///////////////////////////////////////////////////
//                                               //
//          Terminal Server Error codes          //
//                                               //
//                 7000 to 7099                  //
///////////////////////////////////////////////////

//
// MessageId: ERROR_CTX_WINSTATION_NAME_INVALID
//
// MessageText:
//
// The specified session name is invalid.
//
#define ERROR_CTX_WINSTATION_NAME_INVALID 7001L

//
// MessageId: ERROR_CTX_INVALID_PD
//
// MessageText:
//
// The specified protocol driver is invalid.
//
#define ERROR_CTX_INVALID_PD             7002L

//
// MessageId: ERROR_CTX_PD_NOT_FOUND
//
// MessageText:
//
// The specified protocol driver was not found in the system path.
//
#define ERROR_CTX_PD_NOT_FOUND           7003L

//
// MessageId: ERROR_CTX_WD_NOT_FOUND
//
// MessageText:
//
// The specified terminal connection driver was not found in the system path.
//
#define ERROR_CTX_WD_NOT_FOUND           7004L

//
// MessageId: ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY
//
// MessageText:
//
// A registry key for event logging could not be created for this session.
//
#define ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY 7005L

//
// MessageId: ERROR_CTX_SERVICE_NAME_COLLISION
//
// MessageText:
//
// A service with the same name already exists on the system.
//
#define ERROR_CTX_SERVICE_NAME_COLLISION 7006L

//
// MessageId: ERROR_CTX_CLOSE_PENDING
//
// MessageText:
//
// A close operation is pending on the session.
//
#define ERROR_CTX_CLOSE_PENDING          7007L

//
// MessageId: ERROR_CTX_NO_OUTBUF
//
// MessageText:
//
// There are no free output buffers available.
//
#define ERROR_CTX_NO_OUTBUF              7008L

//
// MessageId: ERROR_CTX_MODEM_INF_NOT_FOUND
//
// MessageText:
//
// The MODEM.INF file was not found.
//
#define ERROR_CTX_MODEM_INF_NOT_FOUND    7009L

//
// MessageId: ERROR_CTX_INVALID_MODEMNAME
//
// MessageText:
//
// The modem name was not found in MODEM.INF.
//
#define ERROR_CTX_INVALID_MODEMNAME      7010L

//
// MessageId: ERROR_CTX_MODEM_RESPONSE_ERROR
//
// MessageText:
//
// The modem did not accept the command sent to it. Verify that the configured modem name matches the attached modem.
//
#define ERROR_CTX_MODEM_RESPONSE_ERROR   7011L

//
// MessageId: ERROR_CTX_MODEM_RESPONSE_TIMEOUT
//
// MessageText:
//
// The modem did not respond to the command sent to it. Verify that the modem is properly cabled and powered on.
//
#define ERROR_CTX_MODEM_RESPONSE_TIMEOUT 7012L

//
// MessageId: ERROR_CTX_MODEM_RESPONSE_NO_CARRIER
//
// MessageText:
//
// Carrier detect has failed or carrier has been dropped due to disconnect.
//
#define ERROR_CTX_MODEM_RESPONSE_NO_CARRIER 7013L

//
// MessageId: ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE
//
// MessageText:
//
// Dial tone not detected within the required time. Verify that the phone cable is properly attached and functional.
//
#define ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE 7014L

//
// MessageId: ERROR_CTX_MODEM_RESPONSE_BUSY
//
// MessageText:
//
// Busy signal detected at remote site on callback.
//
#define ERROR_CTX_MODEM_RESPONSE_BUSY    7015L

//
// MessageId: ERROR_CTX_MODEM_RESPONSE_VOICE
//
// MessageText:
//
// Voice detected at remote site on callback.
//
#define ERROR_CTX_MODEM_RESPONSE_VOICE   7016L

//
// MessageId: ERROR_CTX_TD_ERROR
//
// MessageText:
//
// Transport driver error
//
#define ERROR_CTX_TD_ERROR               7017L

//
// MessageId: ERROR_CTX_WINSTATION_NOT_FOUND
//
// MessageText:
//
// The specified session cannot be found.
//
#define ERROR_CTX_WINSTATION_NOT_FOUND   7022L

//
// MessageId: ERROR_CTX_WINSTATION_ALREADY_EXISTS
//
// MessageText:
//
// The specified session name is already in use.
//
#define ERROR_CTX_WINSTATION_ALREADY_EXISTS 7023L

//
// MessageId: ERROR_CTX_WINSTATION_BUSY
//
// MessageText:
//
// The requested operation cannot be completed because the terminal connection is currently busy processing a connect, disconnect, reset, or delete operation.
//
#define ERROR_CTX_WINSTATION_BUSY        7024L

//
// MessageId: ERROR_CTX_BAD_VIDEO_MODE
//
// MessageText:
//
// An attempt has been made to connect to a session whose video mode is not supported by the current client.
//
#define ERROR_CTX_BAD_VIDEO_MODE         7025L

//
// MessageId: ERROR_CTX_GRAPHICS_INVALID
//
// MessageText:
//
// The application attempted to enable DOS graphics mode.
// DOS graphics mode is not supported.
//
#define ERROR_CTX_GRAPHICS_INVALID       7035L

//
// MessageId: ERROR_CTX_LOGON_DISABLED
//
// MessageText:
//
// Your interactive logon privilege has been disabled.
// Please contact your administrator.
//
#define ERROR_CTX_LOGON_DISABLED         7037L

//
// MessageId: ERROR_CTX_NOT_CONSOLE
//
// MessageText:
//
// The requested operation can be performed only on the system console.
// This is most often the result of a driver or system DLL requiring direct console access.
//
#define ERROR_CTX_NOT_CONSOLE            7038L

//
// MessageId: ERROR_CTX_CLIENT_QUERY_TIMEOUT
//
// MessageText:
//
// The client failed to respond to the server connect message.
//
#define ERROR_CTX_CLIENT_QUERY_TIMEOUT   7040L

//
// MessageId: ERROR_CTX_CONSOLE_DISCONNECT
//
// MessageText:
//
// Disconnecting the console session is not supported.
//
#define ERROR_CTX_CONSOLE_DISCONNECT     7041L

//
// MessageId: ERROR_CTX_CONSOLE_CONNECT
//
// MessageText:
//
// Reconnecting a disconnected session to the console is not supported.
//
#define ERROR_CTX_CONSOLE_CONNECT        7042L

//
// MessageId: ERROR_CTX_SHADOW_DENIED
//
// MessageText:
//
// The request to control another session remotely was denied.
//
#define ERROR_CTX_SHADOW_DENIED          7044L

//
// MessageId: ERROR_CTX_WINSTATION_ACCESS_DENIED
//
// MessageText:
//
// The requested session access is denied.
//
#define ERROR_CTX_WINSTATION_ACCESS_DENIED 7045L

//
// MessageId: ERROR_CTX_INVALID_WD
//
// MessageText:
//
// The specified terminal connection driver is invalid.
//
#define ERROR_CTX_INVALID_WD             7049L

//
// MessageId: ERROR_CTX_SHADOW_INVALID
//
// MessageText:
//
// The requested session cannot be controlled remotely.
// This may be because the session is disconnected or does not currently have a user logged on.
//
#define ERROR_CTX_SHADOW_INVALID         7050L

//
// MessageId: ERROR_CTX_SHADOW_DISABLED
//
// MessageText:
//
// The requested session is not configured to allow remote control.
//
#define ERROR_CTX_SHADOW_DISABLED        7051L

//
// MessageId: ERROR_CTX_CLIENT_LICENSE_IN_USE
//
// MessageText:
//
// Your request to connect to this Terminal Server has been rejected. Your Terminal Server client license number is currently being used by another user.
// Please call your system administrator to obtain a unique license number.
//
#define ERROR_CTX_CLIENT_LICENSE_IN_USE  7052L

//
// MessageId: ERROR_CTX_CLIENT_LICENSE_NOT_SET
//
// MessageText:
//
// Your request to connect to this Terminal Server has been rejected. Your Terminal Server client license number has not been entered for this copy of the Terminal Server client.
// Please contact your system administrator.
//
#define ERROR_CTX_CLIENT_LICENSE_NOT_SET 7053L

//
// MessageId: ERROR_CTX_LICENSE_NOT_AVAILABLE
//
// MessageText:
//
// The number of connections to this computer is limited and all connections are in use right now.
// Try connecting later or contact your system administrator.
//
#define ERROR_CTX_LICENSE_NOT_AVAILABLE  7054L

//
// MessageId: ERROR_CTX_LICENSE_CLIENT_INVALID
//
// MessageText:
//
// The client you are using is not licensed to use this system. Your logon request is denied.
//
#define ERROR_CTX_LICENSE_CLIENT_INVALID 7055L

//
// MessageId: ERROR_CTX_LICENSE_EXPIRED
//
// MessageText:
//
// The system license has expired. Your logon request is denied.
//
#define ERROR_CTX_LICENSE_EXPIRED        7056L

//
// MessageId: ERROR_CTX_SHADOW_NOT_RUNNING
//
// MessageText:
//
// Remote control could not be terminated because the specified session is not currently being remotely controlled.
//
#define ERROR_CTX_SHADOW_NOT_RUNNING     7057L

//
// MessageId: ERROR_CTX_SHADOW_ENDED_BY_MODE_CHANGE
//
// MessageText:
//
// The remote control of the console was terminated because the display mode was changed. Changing the display mode in a remote control session is not supported.
//
#define ERROR_CTX_SHADOW_ENDED_BY_MODE_CHANGE 7058L

//
// MessageId: ERROR_ACTIVATION_COUNT_EXCEEDED
//
// MessageText:
//
// Activation has already been reset the maximum number of times for this installation. Your activation timer will not be cleared.
//
#define ERROR_ACTIVATION_COUNT_EXCEEDED  7059L

//
// MessageId: ERROR_CTX_WINSTATIONS_DISABLED
//
// MessageText:
//
// Remote logins are currently disabled.
//
#define ERROR_CTX_WINSTATIONS_DISABLED   7060L

//
// MessageId: ERROR_CTX_ENCRYPTION_LEVEL_REQUIRED
//
// MessageText:
//
// You do not have the proper encryption level to access this Session.
//
#define ERROR_CTX_ENCRYPTION_LEVEL_REQUIRED 7061L

//
// MessageId: ERROR_CTX_SESSION_IN_USE
//
// MessageText:
//
// The user %s\\%s is currently logged on to this computer. Only the current user or an administrator can log on to this computer.
//
#define ERROR_CTX_SESSION_IN_USE         7062L

//
// MessageId: ERROR_CTX_NO_FORCE_LOGOFF
//
// MessageText:
//
// The user %s\\%s is already logged on to the console of this computer. You do not have permission to log in at this time. To resolve this issue, contact %s\\%s and have them log off.
//
#define ERROR_CTX_NO_FORCE_LOGOFF        7063L

//
// MessageId: ERROR_CTX_ACCOUNT_RESTRICTION
//
// MessageText:
//
// Unable to log you on because of an account restriction.
//
#define ERROR_CTX_ACCOUNT_RESTRICTION    7064L

//
// MessageId: ERROR_RDP_PROTOCOL_ERROR
//
// MessageText:
//
// The RDP protocol component %2 detected an error in the protocol stream and has disconnected the client.
//
#define ERROR_RDP_PROTOCOL_ERROR         7065L

//
// MessageId: ERROR_CTX_CDM_CONNECT
//
// MessageText:
//
// The Client Drive Mapping Service Has Connected on Terminal Connection.
//
#define ERROR_CTX_CDM_CONNECT            7066L

//
// MessageId: ERROR_CTX_CDM_DISCONNECT
//
// MessageText:
//
// The Client Drive Mapping Service Has Disconnected on Terminal Connection.
//
#define ERROR_CTX_CDM_DISCONNECT         7067L

//
// MessageId: ERROR_CTX_SECURITY_LAYER_ERROR
//
// MessageText:
//
// The Terminal Server security layer detected an error in the protocol stream and has disconnected the client.
//
#define ERROR_CTX_SECURITY_LAYER_ERROR   7068L

//
// MessageId: ERROR_TS_INCOMPATIBLE_SESSIONS
//
// MessageText:
//
// The target session is incompatible with the current session.
//
#define ERROR_TS_INCOMPATIBLE_SESSIONS   7069L

///////////////////////////////////////////////////
//                                               //
//                  Available                    //
//                                               //
//                 7100 to 7499                  //
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//                                                /
//           Traffic Control Error Codes          /
//                                                /
//                  7500 to 7999                  /
//                                                /
//            defined in: tcerror.h               /
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//                                               //
//           Active Directory Error codes        //
//                                               //
//                 8000 to 8999                  //
///////////////////////////////////////////////////

// *****************
// FACILITY_FILE_REPLICATION_SERVICE
// *****************
//
// MessageId: FRS_ERR_INVALID_API_SEQUENCE
//
// MessageText:
//
// The file replication service API was called incorrectly.
//
#define FRS_ERR_INVALID_API_SEQUENCE     8001L

//
// MessageId: FRS_ERR_STARTING_SERVICE
//
// MessageText:
//
// The file replication service cannot be started.
//
#define FRS_ERR_STARTING_SERVICE         8002L

//
// MessageId: FRS_ERR_STOPPING_SERVICE
//
// MessageText:
//
// The file replication service cannot be stopped.
//
#define FRS_ERR_STOPPING_SERVICE         8003L

//
// MessageId: FRS_ERR_INTERNAL_API
//
// MessageText:
//
// The file replication service API terminated the request.
// The event log may have more information.
//
#define FRS_ERR_INTERNAL_API             8004L

//
// MessageId: FRS_ERR_INTERNAL
//
// MessageText:
//
// The file replication service terminated the request.
// The event log may have more information.
//
#define FRS_ERR_INTERNAL                 8005L

//
// MessageId: FRS_ERR_SERVICE_COMM
//
// MessageText:
//
// The file replication service cannot be contacted.
// The event log may have more information.
//
#define FRS_ERR_SERVICE_COMM             8006L

//
// MessageId: FRS_ERR_INSUFFICIENT_PRIV
//
// MessageText:
//
// The file replication service cannot satisfy the request because the user has insufficient privileges.
// The event log may have more information.
//
#define FRS_ERR_INSUFFICIENT_PRIV        8007L

//
// MessageId: FRS_ERR_AUTHENTICATION
//
// MessageText:
//
// The file replication service cannot satisfy the request because authenticated RPC is not available.
// The event log may have more information.
//
#define FRS_ERR_AUTHENTICATION           8008L

//
// MessageId: FRS_ERR_PARENT_INSUFFICIENT_PRIV
//
// MessageText:
//
// The file replication service cannot satisfy the request because the user has insufficient privileges on the domain controller.
// The event log may have more information.
//
#define FRS_ERR_PARENT_INSUFFICIENT_PRIV 8009L

//
// MessageId: FRS_ERR_PARENT_AUTHENTICATION
//
// MessageText:
//
// The file replication service cannot satisfy the request because authenticated RPC is not available on the domain controller.
// The event log may have more information.
//
#define FRS_ERR_PARENT_AUTHENTICATION    8010L

//
// MessageId: FRS_ERR_CHILD_TO_PARENT_COMM
//
// MessageText:
//
// The file replication service cannot communicate with the file replication service on the domain controller.
// The event log may have more information.
//
#define FRS_ERR_CHILD_TO_PARENT_COMM     8011L

//
// MessageId: FRS_ERR_PARENT_TO_CHILD_COMM
//
// MessageText:
//
// The file replication service on the domain controller cannot communicate with the file replication service on this computer.
// The event log may have more information.
//
#define FRS_ERR_PARENT_TO_CHILD_COMM     8012L

//
// MessageId: FRS_ERR_SYSVOL_POPULATE
//
// MessageText:
//
// The file replication service cannot populate the system volume because of an internal error.
// The event log may have more information.
//
#define FRS_ERR_SYSVOL_POPULATE          8013L

//
// MessageId: FRS_ERR_SYSVOL_POPULATE_TIMEOUT
//
// MessageText:
//
// The file replication service cannot populate the system volume because of an internal timeout.
// The event log may have more information.
//
#define FRS_ERR_SYSVOL_POPULATE_TIMEOUT  8014L

//
// MessageId: FRS_ERR_SYSVOL_IS_BUSY
//
// MessageText:
//
// The file replication service cannot process the request. The system volume is busy with a previous request.
//
#define FRS_ERR_SYSVOL_IS_BUSY           8015L

//
// MessageId: FRS_ERR_SYSVOL_DEMOTE
//
// MessageText:
//
// The file replication service cannot stop replicating the system volume because of an internal error.
// The event log may have more information.
//
#define FRS_ERR_SYSVOL_DEMOTE            8016L

//
// MessageId: FRS_ERR_INVALID_SERVICE_PARAMETER
//
// MessageText:
//
// The file replication service detected an invalid parameter.
//
#define FRS_ERR_INVALID_SERVICE_PARAMETER 8017L

// *****************
// FACILITY DIRECTORY SERVICE
// *****************
#define DS_S_SUCCESS NO_ERROR
//
// MessageId: ERROR_DS_NOT_INSTALLED
//
// MessageText:
//
// An error occurred while installing the directory service. For more information, see the event log.
//
#define ERROR_DS_NOT_INSTALLED           8200L

//
// MessageId: ERROR_DS_MEMBERSHIP_EVALUATED_LOCALLY
//
// MessageText:
//
// The directory service evaluated group memberships locally.
//
#define ERROR_DS_MEMBERSHIP_EVALUATED_LOCALLY 8201L

//
// MessageId: ERROR_DS_NO_ATTRIBUTE_OR_VALUE
//
// MessageText:
//
// The specified directory service attribute or value does not exist.
//
#define ERROR_DS_NO_ATTRIBUTE_OR_VALUE   8202L

//
// MessageId: ERROR_DS_INVALID_ATTRIBUTE_SYNTAX
//
// MessageText:
//
// The attribute syntax specified to the directory service is invalid.
//
#define ERROR_DS_INVALID_ATTRIBUTE_SYNTAX 8203L

//
// MessageId: ERROR_DS_ATTRIBUTE_TYPE_UNDEFINED
//
// MessageText:
//
// The attribute type specified to the directory service is not defined.
//
#define ERROR_DS_ATTRIBUTE_TYPE_UNDEFINED 8204L

//
// MessageId: ERROR_DS_ATTRIBUTE_OR_VALUE_EXISTS
//
// MessageText:
//
// The specified directory service attribute or value already exists.
//
#define ERROR_DS_ATTRIBUTE_OR_VALUE_EXISTS 8205L

//
// MessageId: ERROR_DS_BUSY
//
// MessageText:
//
// The directory service is busy.
//
#define ERROR_DS_BUSY                    8206L

//
// MessageId: ERROR_DS_UNAVAILABLE
//
// MessageText:
//
// The directory service is unavailable.
//
#define ERROR_DS_UNAVAILABLE             8207L

//
// MessageId: ERROR_DS_NO_RIDS_ALLOCATED
//
// MessageText:
//
// The directory service was unable to allocate a relative identifier.
//
#define ERROR_DS_NO_RIDS_ALLOCATED       8208L

//
// MessageId: ERROR_DS_NO_MORE_RIDS
//
// MessageText:
//
// The directory service has exhausted the pool of relative identifiers.
//
#define ERROR_DS_NO_MORE_RIDS            8209L

//
// MessageId: ERROR_DS_INCORRECT_ROLE_OWNER
//
// MessageText:
//
// The requested operation could not be performed because the directory service is not the master for that type of operation.
//
#define ERROR_DS_INCORRECT_ROLE_OWNER    8210L

//
// MessageId: ERROR_DS_RIDMGR_INIT_ERROR
//
// MessageText:
//
// The directory service was unable to initialize the subsystem that allocates relative identifiers.
//
#define ERROR_DS_RIDMGR_INIT_ERROR       8211L

//
// MessageId: ERROR_DS_OBJ_CLASS_VIOLATION
//
// MessageText:
//
// The requested operation did not satisfy one or more constraints associated with the class of the object.
//
#define ERROR_DS_OBJ_CLASS_VIOLATION     8212L

//
// MessageId: ERROR_DS_CANT_ON_NON_LEAF
//
// MessageText:
//
// The directory service can perform the requested operation only on a leaf object.
//
#define ERROR_DS_CANT_ON_NON_LEAF        8213L

//
// MessageId: ERROR_DS_CANT_ON_RDN
//
// MessageText:
//
// The directory service cannot perform the requested operation on the RDN attribute of an object.
//
#define ERROR_DS_CANT_ON_RDN             8214L

//
// MessageId: ERROR_DS_CANT_MOD_OBJ_CLASS
//
// MessageText:
//
// The directory service detected an attempt to modify the object class of an object.
//
#define ERROR_DS_CANT_MOD_OBJ_CLASS      8215L

//
// MessageId: ERROR_DS_CROSS_DOM_MOVE_ERROR
//
// MessageText:
//
// The requested cross-domain move operation could not be performed.
//
#define ERROR_DS_CROSS_DOM_MOVE_ERROR    8216L

//
// MessageId: ERROR_DS_GC_NOT_AVAILABLE
//
// MessageText:
//
// Unable to contact the global catalog server.
//
#define ERROR_DS_GC_NOT_AVAILABLE        8217L

//
// MessageId: ERROR_SHARED_POLICY
//
// MessageText:
//
// The policy object is shared and can only be modified at the root.
//
#define ERROR_SHARED_POLICY              8218L

//
// MessageId: ERROR_POLICY_OBJECT_NOT_FOUND
//
// MessageText:
//
// The policy object does not exist.
//
#define ERROR_POLICY_OBJECT_NOT_FOUND    8219L

//
// MessageId: ERROR_POLICY_ONLY_IN_DS
//
// MessageText:
//
// The requested policy information is only in the directory service.
//
#define ERROR_POLICY_ONLY_IN_DS          8220L

//
// MessageId: ERROR_PROMOTION_ACTIVE
//
// MessageText:
//
// A domain controller promotion is currently active.
//
#define ERROR_PROMOTION_ACTIVE           8221L

//
// MessageId: ERROR_NO_PROMOTION_ACTIVE
//
// MessageText:
//
// A domain controller promotion is not currently active
//
#define ERROR_NO_PROMOTION_ACTIVE        8222L

// 8223 unused
//
// MessageId: ERROR_DS_OPERATIONS_ERROR
//
// MessageText:
//
// An operations error occurred.
//
#define ERROR_DS_OPERATIONS_ERROR        8224L

//
// MessageId: ERROR_DS_PROTOCOL_ERROR
//
// MessageText:
//
// A protocol error occurred.
//
#define ERROR_DS_PROTOCOL_ERROR          8225L

//
// MessageId: ERROR_DS_TIMELIMIT_EXCEEDED
//
// MessageText:
//
// The time limit for this request was exceeded.
//
#define ERROR_DS_TIMELIMIT_EXCEEDED      8226L

//
// MessageId: ERROR_DS_SIZELIMIT_EXCEEDED
//
// MessageText:
//
// The size limit for this request was exceeded.
//
#define ERROR_DS_SIZELIMIT_EXCEEDED      8227L

//
// MessageId: ERROR_DS_ADMIN_LIMIT_EXCEEDED
//
// MessageText:
//
// The administrative limit for this request was exceeded.
//
#define ERROR_DS_ADMIN_LIMIT_EXCEEDED    8228L

//
// MessageId: ERROR_DS_COMPARE_FALSE
//
// MessageText:
//
// The compare response was false.
//
#define ERROR_DS_COMPARE_FALSE           8229L

//
// MessageId: ERROR_DS_COMPARE_TRUE
//
// MessageText:
//
// The compare response was true.
//
#define ERROR_DS_COMPARE_TRUE            8230L

//
// MessageId: ERROR_DS_AUTH_METHOD_NOT_SUPPORTED
//
// MessageText:
//
// The requested authentication method is not supported by the server.
//
#define ERROR_DS_AUTH_METHOD_NOT_SUPPORTED 8231L

//
// MessageId: ERROR_DS_STRONG_AUTH_REQUIRED
//
// MessageText:
//
// A more secure authentication method is required for this server.
//
#define ERROR_DS_STRONG_AUTH_REQUIRED    8232L

//
// MessageId: ERROR_DS_INAPPROPRIATE_AUTH
//
// MessageText:
//
// Inappropriate authentication.
//
#define ERROR_DS_INAPPROPRIATE_AUTH      8233L

//
// MessageId: ERROR_DS_AUTH_UNKNOWN
//
// MessageText:
//
// The authentication mechanism is unknown.
//
#define ERROR_DS_AUTH_UNKNOWN            8234L

//
// MessageId: ERROR_DS_REFERRAL
//
// MessageText:
//
// A referral was returned from the server.
//
#define ERROR_DS_REFERRAL                8235L

//
// MessageId: ERROR_DS_UNAVAILABLE_CRIT_EXTENSION
//
// MessageText:
//
// The server does not support the requested critical extension.
//
#define ERROR_DS_UNAVAILABLE_CRIT_EXTENSION 8236L

//
// MessageId: ERROR_DS_CONFIDENTIALITY_REQUIRED
//
// MessageText:
//
// This request requires a secure connection.
//
#define ERROR_DS_CONFIDENTIALITY_REQUIRED 8237L

//
// MessageId: ERROR_DS_INAPPROPRIATE_MATCHING
//
// MessageText:
//
// Inappropriate matching.
//
#define ERROR_DS_INAPPROPRIATE_MATCHING  8238L

//
// MessageId: ERROR_DS_CONSTRAINT_VIOLATION
//
// MessageText:
//
// A constraint violation occurred.
//
#define ERROR_DS_CONSTRAINT_VIOLATION    8239L

//
// MessageId: ERROR_DS_NO_SUCH_OBJECT
//
// MessageText:
//
// There is no such object on the server.
//
#define ERROR_DS_NO_SUCH_OBJECT          8240L

//
// MessageId: ERROR_DS_ALIAS_PROBLEM
//
// MessageText:
//
// There is an alias problem.
//
#define ERROR_DS_ALIAS_PROBLEM           8241L

//
// MessageId: ERROR_DS_INVALID_DN_SYNTAX
//
// MessageText:
//
// An invalid dn syntax has been specified.
//
#define ERROR_DS_INVALID_DN_SYNTAX       8242L

//
// MessageId: ERROR_DS_IS_LEAF
//
// MessageText:
//
// The object is a leaf object.
//
#define ERROR_DS_IS_LEAF                 8243L

//
// MessageId: ERROR_DS_ALIAS_DEREF_PROBLEM
//
// MessageText:
//
// There is an alias dereferencing problem.
//
#define ERROR_DS_ALIAS_DEREF_PROBLEM     8244L

//
// MessageId: ERROR_DS_UNWILLING_TO_PERFORM
//
// MessageText:
//
// The server is unwilling to process the request.
//
#define ERROR_DS_UNWILLING_TO_PERFORM    8245L

//
// MessageId: ERROR_DS_LOOP_DETECT
//
// MessageText:
//
// A loop has been detected.
//
#define ERROR_DS_LOOP_DETECT             8246L

//
// MessageId: ERROR_DS_NAMING_VIOLATION
//
// MessageText:
//
// There is a naming violation.
//
#define ERROR_DS_NAMING_VIOLATION        8247L

//
// MessageId: ERROR_DS_OBJECT_RESULTS_TOO_LARGE
//
// MessageText:
//
// The result set is too large.
//
#define ERROR_DS_OBJECT_RESULTS_TOO_LARGE 8248L

//
// MessageId: ERROR_DS_AFFECTS_MULTIPLE_DSAS
//
// MessageText:
//
// The operation affects multiple DSAs
//
#define ERROR_DS_AFFECTS_MULTIPLE_DSAS   8249L

//
// MessageId: ERROR_DS_SERVER_DOWN
//
// MessageText:
//
// The server is not operational.
//
#define ERROR_DS_SERVER_DOWN             8250L

//
// MessageId: ERROR_DS_LOCAL_ERROR
//
// MessageText:
//
// A local error has occurred.
//
#define ERROR_DS_LOCAL_ERROR             8251L

//
// MessageId: ERROR_DS_ENCODING_ERROR
//
// MessageText:
//
// An encoding error has occurred.
//
#define ERROR_DS_ENCODING_ERROR          8252L

//
// MessageId: ERROR_DS_DECODING_ERROR
//
// MessageText:
//
// A decoding error has occurred.
//
#define ERROR_DS_DECODING_ERROR          8253L

//
// MessageId: ERROR_DS_FILTER_UNKNOWN
//
// MessageText:
//
// The search filter cannot be recognized.
//
#define ERROR_DS_FILTER_UNKNOWN          8254L

//
// MessageId: ERROR_DS_PARAM_ERROR
//
// MessageText:
//
// One or more parameters are illegal.
//
#define ERROR_DS_PARAM_ERROR             8255L

//
// MessageId: ERROR_DS_NOT_SUPPORTED
//
// MessageText:
//
// The specified method is not supported.
//
#define ERROR_DS_NOT_SUPPORTED           8256L

//
// MessageId: ERROR_DS_NO_RESULTS_RETURNED
//
// MessageText:
//
// No results were returned.
//
#define ERROR_DS_NO_RESULTS_RETURNED     8257L

//
// MessageId: ERROR_DS_CONTROL_NOT_FOUND
//
// MessageText:
//
// The specified control is not supported by the server.
//
#define ERROR_DS_CONTROL_NOT_FOUND       8258L

//
// MessageId: ERROR_DS_CLIENT_LOOP
//
// MessageText:
//
// A referral loop was detected by the client.
//
#define ERROR_DS_CLIENT_LOOP             8259L

//
// MessageId: ERROR_DS_REFERRAL_LIMIT_EXCEEDED
//
// MessageText:
//
// The preset referral limit was exceeded.
//
#define ERROR_DS_REFERRAL_LIMIT_EXCEEDED 8260L

//
// MessageId: ERROR_DS_SORT_CONTROL_MISSING
//
// MessageText:
//
// The search requires a SORT control.
//
#define ERROR_DS_SORT_CONTROL_MISSING    8261L

//
// MessageId: ERROR_DS_OFFSET_RANGE_ERROR
//
// MessageText:
//
// The search results exceed the offset range specified.
//
#define ERROR_DS_OFFSET_RANGE_ERROR      8262L

//
// MessageId: ERROR_DS_ROOT_MUST_BE_NC
//
// MessageText:
//
// The root object must be the head of a naming context. The root object cannot have an instantiated parent.
//
#define ERROR_DS_ROOT_MUST_BE_NC         8301L

//
// MessageId: ERROR_DS_ADD_REPLICA_INHIBITED
//
// MessageText:
//
// The add replica operation cannot be performed. The naming context must be writeable in order to create the replica.
//
#define ERROR_DS_ADD_REPLICA_INHIBITED   8302L

//
// MessageId: ERROR_DS_ATT_NOT_DEF_IN_SCHEMA
//
// MessageText:
//
// A reference to an attribute that is not defined in the schema occurred.
//
#define ERROR_DS_ATT_NOT_DEF_IN_SCHEMA   8303L

//
// MessageId: ERROR_DS_MAX_OBJ_SIZE_EXCEEDED
//
// MessageText:
//
// The maximum size of an object has been exceeded.
//
#define ERROR_DS_MAX_OBJ_SIZE_EXCEEDED   8304L

//
// MessageId: ERROR_DS_OBJ_STRING_NAME_EXISTS
//
// MessageText:
//
// An attempt was made to add an object to the directory with a name that is already in use.
//
#define ERROR_DS_OBJ_STRING_NAME_EXISTS  8305L

//
// MessageId: ERROR_DS_NO_RDN_DEFINED_IN_SCHEMA
//
// MessageText:
//
// An attempt was made to add an object of a class that does not have an RDN defined in the schema.
//
#define ERROR_DS_NO_RDN_DEFINED_IN_SCHEMA 8306L

//
// MessageId: ERROR_DS_RDN_DOESNT_MATCH_SCHEMA
//
// MessageText:
//
// An attempt was made to add an object using an RDN that is not the RDN defined in the schema.
//
#define ERROR_DS_RDN_DOESNT_MATCH_SCHEMA 8307L

//
// MessageId: ERROR_DS_NO_REQUESTED_ATTS_FOUND
//
// MessageText:
//
// None of the requested attributes were found on the objects.
//
#define ERROR_DS_NO_REQUESTED_ATTS_FOUND 8308L

//
// MessageId: ERROR_DS_USER_BUFFER_TO_SMALL
//
// MessageText:
//
// The user buffer is too small.
//
#define ERROR_DS_USER_BUFFER_TO_SMALL    8309L

//
// MessageId: ERROR_DS_ATT_IS_NOT_ON_OBJ
//
// MessageText:
//
// The attribute specified in the operation is not present on the object.
//
#define ERROR_DS_ATT_IS_NOT_ON_OBJ       8310L

//
// MessageId: ERROR_DS_ILLEGAL_MOD_OPERATION
//
// MessageText:
//
// Illegal modify operation. Some aspect of the modification is not permitted.
//
#define ERROR_DS_ILLEGAL_MOD_OPERATION   8311L

//
// MessageId: ERROR_DS_OBJ_TOO_LARGE
//
// MessageText:
//
// The specified object is too large.
//
#define ERROR_DS_OBJ_TOO_LARGE           8312L

//
// MessageId: ERROR_DS_BAD_INSTANCE_TYPE
//
// MessageText:
//
// The specified instance type is not valid.
//
#define ERROR_DS_BAD_INSTANCE_TYPE       8313L

//
// MessageId: ERROR_DS_MASTERDSA_REQUIRED
//
// MessageText:
//
// The operation must be performed at a master DSA.
//
#define ERROR_DS_MASTERDSA_REQUIRED      8314L

//
// MessageId: ERROR_DS_OBJECT_CLASS_REQUIRED
//
// MessageText:
//
// The object class attribute must be specified.
//
#define ERROR_DS_OBJECT_CLASS_REQUIRED   8315L

//
// MessageId: ERROR_DS_MISSING_REQUIRED_ATT
//
// MessageText:
//
// A required attribute is missing.
//
#define ERROR_DS_MISSING_REQUIRED_ATT    8316L

//
// MessageId: ERROR_DS_ATT_NOT_DEF_FOR_CLASS
//
// MessageText:
//
// An attempt was made to modify an object to include an attribute that is not legal for its class.
//
#define ERROR_DS_ATT_NOT_DEF_FOR_CLASS   8317L

//
// MessageId: ERROR_DS_ATT_ALREADY_EXISTS
//
// MessageText:
//
// The specified attribute is already present on the object.
//
#define ERROR_DS_ATT_ALREADY_EXISTS      8318L

// 8319 unused
//
// MessageId: ERROR_DS_CANT_ADD_ATT_VALUES
//
// MessageText:
//
// The specified attribute is not present, or has no values.
//
#define ERROR_DS_CANT_ADD_ATT_VALUES     8320L

//
// MessageId: ERROR_DS_SINGLE_VALUE_CONSTRAINT
//
// MessageText:
//
// Multiple values were specified for an attribute that can have only one value.
//
#define ERROR_DS_SINGLE_VALUE_CONSTRAINT 8321L

//
// MessageId: ERROR_DS_RANGE_CONSTRAINT
//
// MessageText:
//
// A value for the attribute was not in the acceptable range of values.
//
#define ERROR_DS_RANGE_CONSTRAINT        8322L

//
// MessageId: ERROR_DS_ATT_VAL_ALREADY_EXISTS
//
// MessageText:
//
// The specified value already exists.
//
#define ERROR_DS_ATT_VAL_ALREADY_EXISTS  8323L

//
// MessageId: ERROR_DS_CANT_REM_MISSING_ATT
//
// MessageText:
//
// The attribute cannot be removed because it is not present on the object.
//
#define ERROR_DS_CANT_REM_MISSING_ATT    8324L

//
// MessageId: ERROR_DS_CANT_REM_MISSING_ATT_VAL
//
// MessageText:
//
// The attribute value cannot be removed because it is not present on the object.
//
#define ERROR_DS_CANT_REM_MISSING_ATT_VAL 8325L

//
// MessageId: ERROR_DS_ROOT_CANT_BE_SUBREF
//
// MessageText:
//
// The specified root object cannot be a subref.
//
#define ERROR_DS_ROOT_CANT_BE_SUBREF     8326L

//
// MessageId: ERROR_DS_NO_CHAINING
//
// MessageText:
//
// Chaining is not permitted.
//
#define ERROR_DS_NO_CHAINING             8327L

//
// MessageId: ERROR_DS_NO_CHAINED_EVAL
//
// MessageText:
//
// Chained evaluation is not permitted.
//
#define ERROR_DS_NO_CHAINED_EVAL         8328L

//
// MessageId: ERROR_DS_NO_PARENT_OBJECT
//
// MessageText:
//
// The operation could not be performed because the object's parent is either uninstantiated or deleted.
//
#define ERROR_DS_NO_PARENT_OBJECT        8329L

//
// MessageId: ERROR_DS_PARENT_IS_AN_ALIAS
//
// MessageText:
//
// Having a parent that is an alias is not permitted. Aliases are leaf objects.
//
#define ERROR_DS_PARENT_IS_AN_ALIAS      8330L

//
// MessageId: ERROR_DS_CANT_MIX_MASTER_AND_REPS
//
// MessageText:
//
// The object and parent must be of the same type, either both masters or both replicas.
//
#define ERROR_DS_CANT_MIX_MASTER_AND_REPS 8331L

//
// MessageId: ERROR_DS_CHILDREN_EXIST
//
// MessageText:
//
// The operation cannot be performed because child objects exist. This operation can only be performed on a leaf object.
//
#define ERROR_DS_CHILDREN_EXIST          8332L

//
// MessageId: ERROR_DS_OBJ_NOT_FOUND
//
// MessageText:
//
// Directory object not found.
//
#define ERROR_DS_OBJ_NOT_FOUND           8333L

//
// MessageId: ERROR_DS_ALIASED_OBJ_MISSING
//
// MessageText:
//
// The aliased object is missing.
//
#define ERROR_DS_ALIASED_OBJ_MISSING     8334L

//
// MessageId: ERROR_DS_BAD_NAME_SYNTAX
//
// MessageText:
//
// The object name has bad syntax.
//
#define ERROR_DS_BAD_NAME_SYNTAX         8335L

//
// MessageId: ERROR_DS_ALIAS_POINTS_TO_ALIAS
//
// MessageText:
//
// It is not permitted for an alias to refer to another alias.
//
#define ERROR_DS_ALIAS_POINTS_TO_ALIAS   8336L

//
// MessageId: ERROR_DS_CANT_DEREF_ALIAS
//
// MessageText:
//
// The alias cannot be dereferenced.
//
#define ERROR_DS_CANT_DEREF_ALIAS        8337L

//
// MessageId: ERROR_DS_OUT_OF_SCOPE
//
// MessageText:
//
// The operation is out of scope.
//
#define ERROR_DS_OUT_OF_SCOPE            8338L

//
// MessageId: ERROR_DS_OBJECT_BEING_REMOVED
//
// MessageText:
//
// The operation cannot continue because the object is in the process of being removed.
//
#define ERROR_DS_OBJECT_BEING_REMOVED    8339L

//
// MessageId: ERROR_DS_CANT_DELETE_DSA_OBJ
//
// MessageText:
//
// The DSA object cannot be deleted.
//
#define ERROR_DS_CANT_DELETE_DSA_OBJ     8340L

//
// MessageId: ERROR_DS_GENERIC_ERROR
//
// MessageText:
//
// A directory service error has occurred.
//
#define ERROR_DS_GENERIC_ERROR           8341L

//
// MessageId: ERROR_DS_DSA_MUST_BE_INT_MASTER
//
// MessageText:
//
// The operation can only be performed on an internal master DSA object.
//
#define ERROR_DS_DSA_MUST_BE_INT_MASTER  8342L

//
// MessageId: ERROR_DS_CLASS_NOT_DSA
//
// MessageText:
//
// The object must be of class DSA.
//
#define ERROR_DS_CLASS_NOT_DSA           8343L

//
// MessageId: ERROR_DS_INSUFF_ACCESS_RIGHTS
//
// MessageText:
//
// Insufficient access rights to perform the operation.
//
#define ERROR_DS_INSUFF_ACCESS_RIGHTS    8344L

//
// MessageId: ERROR_DS_ILLEGAL_SUPERIOR
//
// MessageText:
//
// The object cannot be added because the parent is not on the list of possible superiors.
//
#define ERROR_DS_ILLEGAL_SUPERIOR        8345L

//
// MessageId: ERROR_DS_ATTRIBUTE_OWNED_BY_SAM
//
// MessageText:
//
// Access to the attribute is not permitted because the attribute is owned by the Security Accounts Manager (SAM).
//
#define ERROR_DS_ATTRIBUTE_OWNED_BY_SAM  8346L

//
// MessageId: ERROR_DS_NAME_TOO_MANY_PARTS
//
// MessageText:
//
// The name has too many parts.
//
#define ERROR_DS_NAME_TOO_MANY_PARTS     8347L

//
// MessageId: ERROR_DS_NAME_TOO_LONG
//
// MessageText:
//
// The name is too long.
//
#define ERROR_DS_NAME_TOO_LONG           8348L

//
// MessageId: ERROR_DS_NAME_VALUE_TOO_LONG
//
// MessageText:
//
// The name value is too long.
//
#define ERROR_DS_NAME_VALUE_TOO_LONG     8349L

//
// MessageId: ERROR_DS_NAME_UNPARSEABLE
//
// MessageText:
//
// The directory service encountered an error parsing a name.
//
#define ERROR_DS_NAME_UNPARSEABLE        8350L

//
// MessageId: ERROR_DS_NAME_TYPE_UNKNOWN
//
// MessageText:
//
// The directory service cannot get the attribute type for a name.
//
#define ERROR_DS_NAME_TYPE_UNKNOWN       8351L

//
// MessageId: ERROR_DS_NOT_AN_OBJECT
//
// MessageText:
//
// The name does not identify an object; the name identifies a phantom.
//
#define ERROR_DS_NOT_AN_OBJECT           8352L

//
// MessageId: ERROR_DS_SEC_DESC_TOO_SHORT
//
// MessageText:
//
// The security descriptor is too short.
//
#define ERROR_DS_SEC_DESC_TOO_SHORT      8353L

//
// MessageId: ERROR_DS_SEC_DESC_INVALID
//
// MessageText:
//
// The security descriptor is invalid.
//
#define ERROR_DS_SEC_DESC_INVALID        8354L

//
// MessageId: ERROR_DS_NO_DELETED_NAME
//
// MessageText:
//
// Failed to create name for deleted object.
//
#define ERROR_DS_NO_DELETED_NAME         8355L

//
// MessageId: ERROR_DS_SUBREF_MUST_HAVE_PARENT
//
// MessageText:
//
// The parent of a new subref must exist.
//
#define ERROR_DS_SUBREF_MUST_HAVE_PARENT 8356L

//
// MessageId: ERROR_DS_NCNAME_MUST_BE_NC
//
// MessageText:
//
// The object must be a naming context.
//
#define ERROR_DS_NCNAME_MUST_BE_NC       8357L

//
// MessageId: ERROR_DS_CANT_ADD_SYSTEM_ONLY
//
// MessageText:
//
// It is not permitted to add an attribute which is owned by the system.
//
#define ERROR_DS_CANT_ADD_SYSTEM_ONLY    8358L

//
// MessageId: ERROR_DS_CLASS_MUST_BE_CONCRETE
//
// MessageText:
//
// The class of the object must be structural; you cannot instantiate an abstract class.
//
#define ERROR_DS_CLASS_MUST_BE_CONCRETE  8359L

//
// MessageId: ERROR_DS_INVALID_DMD
//
// MessageText:
//
// The schema object could not be found.
//
#define ERROR_DS_INVALID_DMD             8360L

//
// MessageId: ERROR_DS_OBJ_GUID_EXISTS
//
// MessageText:
//
// A local object with this GUID (dead or alive) already exists.
//
#define ERROR_DS_OBJ_GUID_EXISTS         8361L

//
// MessageId: ERROR_DS_NOT_ON_BACKLINK
//
// MessageText:
//
// The operation cannot be performed on a back link.
//
#define ERROR_DS_NOT_ON_BACKLINK         8362L

//
// MessageId: ERROR_DS_NO_CROSSREF_FOR_NC
//
// MessageText:
//
// The cross reference for the specified naming context could not be found.
//
#define ERROR_DS_NO_CROSSREF_FOR_NC      8363L

//
// MessageId: ERROR_DS_SHUTTING_DOWN
//
// MessageText:
//
// The operation could not be performed because the directory service is shutting down.
//
#define ERROR_DS_SHUTTING_DOWN           8364L

//
// MessageId: ERROR_DS_UNKNOWN_OPERATION
//
// MessageText:
//
// The directory service request is invalid.
//
#define ERROR_DS_UNKNOWN_OPERATION       8365L

//
// MessageId: ERROR_DS_INVALID_ROLE_OWNER
//
// MessageText:
//
// The role owner attribute could not be read.
//
#define ERROR_DS_INVALID_ROLE_OWNER      8366L

//
// MessageId: ERROR_DS_COULDNT_CONTACT_FSMO
//
// MessageText:
//
// The requested FSMO operation failed. The current FSMO holder could not be contacted.
//
#define ERROR_DS_COULDNT_CONTACT_FSMO    8367L

//
// MessageId: ERROR_DS_CROSS_NC_DN_RENAME
//
// MessageText:
//
// Modification of a DN across a naming context is not permitted.
//
#define ERROR_DS_CROSS_NC_DN_RENAME      8368L

//
// MessageId: ERROR_DS_CANT_MOD_SYSTEM_ONLY
//
// MessageText:
//
// The attribute cannot be modified because it is owned by the system.
//
#define ERROR_DS_CANT_MOD_SYSTEM_ONLY    8369L

//
// MessageId: ERROR_DS_REPLICATOR_ONLY
//
// MessageText:
//
// Only the replicator can perform this function.
//
#define ERROR_DS_REPLICATOR_ONLY         8370L

//
// MessageId: ERROR_DS_OBJ_CLASS_NOT_DEFINED
//
// MessageText:
//
// The specified class is not defined.
//
#define ERROR_DS_OBJ_CLASS_NOT_DEFINED   8371L

//
// MessageId: ERROR_DS_OBJ_CLASS_NOT_SUBCLASS
//
// MessageText:
//
// The specified class is not a subclass.
//
#define ERROR_DS_OBJ_CLASS_NOT_SUBCLASS  8372L

//
// MessageId: ERROR_DS_NAME_REFERENCE_INVALID
//
// MessageText:
//
// The name reference is invalid.
//
#define ERROR_DS_NAME_REFERENCE_INVALID  8373L

//
// MessageId: ERROR_DS_CROSS_REF_EXISTS
//
// MessageText:
//
// A cross reference already exists.
//
#define ERROR_DS_CROSS_REF_EXISTS        8374L

//
// MessageId: ERROR_DS_CANT_DEL_MASTER_CROSSREF
//
// MessageText:
//
// It is not permitted to delete a master cross reference.
//
#define ERROR_DS_CANT_DEL_MASTER_CROSSREF 8375L

//
// MessageId: ERROR_DS_SUBTREE_NOTIFY_NOT_NC_HEAD
//
// MessageText:
//
// Subtree notifications are only supported on NC heads.
//
#define ERROR_DS_SUBTREE_NOTIFY_NOT_NC_HEAD 8376L

//
// MessageId: ERROR_DS_NOTIFY_FILTER_TOO_COMPLEX
//
// MessageText:
//
// Notification filter is too complex.
//
#define ERROR_DS_NOTIFY_FILTER_TOO_COMPLEX 8377L

//
// MessageId: ERROR_DS_DUP_RDN
//
// MessageText:
//
// Schema update failed: duplicate RDN.
//
#define ERROR_DS_DUP_RDN                 8378L

//
// MessageId: ERROR_DS_DUP_OID
//
// MessageText:
//
// Schema update failed: duplicate OID.
//
#define ERROR_DS_DUP_OID                 8379L

//
// MessageId: ERROR_DS_DUP_MAPI_ID
//
// MessageText:
//
// Schema update failed: duplicate MAPI identifier.
//
#define ERROR_DS_DUP_MAPI_ID             8380L

//
// MessageId: ERROR_DS_DUP_SCHEMA_ID_GUID
//
// MessageText:
//
// Schema update failed: duplicate schema-id GUID.
//
#define ERROR_DS_DUP_SCHEMA_ID_GUID      8381L

//
// MessageId: ERROR_DS_DUP_LDAP_DISPLAY_NAME
//
// MessageText:
//
// Schema update failed: duplicate LDAP display name.
//
#define ERROR_DS_DUP_LDAP_DISPLAY_NAME   8382L

//
// MessageId: ERROR_DS_SEMANTIC_ATT_TEST
//
// MessageText:
//
// Schema update failed: range-lower less than range upper.
//
#define ERROR_DS_SEMANTIC_ATT_TEST       8383L

//
// MessageId: ERROR_DS_SYNTAX_MISMATCH
//
// MessageText:
//
// Schema update failed: syntax mismatch.
//
#define ERROR_DS_SYNTAX_MISMATCH         8384L

//
// MessageId: ERROR_DS_EXISTS_IN_MUST_HAVE
//
// MessageText:
//
// Schema deletion failed: attribute is used in must-contain.
//
#define ERROR_DS_EXISTS_IN_MUST_HAVE     8385L

//
// MessageId: ERROR_DS_EXISTS_IN_MAY_HAVE
//
// MessageText:
//
// Schema deletion failed: attribute is used in may-contain.
//
#define ERROR_DS_EXISTS_IN_MAY_HAVE      8386L

//
// MessageId: ERROR_DS_NONEXISTENT_MAY_HAVE
//
// MessageText:
//
// Schema update failed: attribute in may-contain does not exist.
//
#define ERROR_DS_NONEXISTENT_MAY_HAVE    8387L

//
// MessageId: ERROR_DS_NONEXISTENT_MUST_HAVE
//
// MessageText:
//
// Schema update failed: attribute in must-contain does not exist.
//
#define ERROR_DS_NONEXISTENT_MUST_HAVE   8388L

//
// MessageId: ERROR_DS_AUX_CLS_TEST_FAIL
//
// MessageText:
//
// Schema update failed: class in aux-class list does not exist or is not an auxiliary class.
//
#define ERROR_DS_AUX_CLS_TEST_FAIL       8389L

//
// MessageId: ERROR_DS_NONEXISTENT_POSS_SUP
//
// MessageText:
//
// Schema update failed: class in poss-superiors does not exist.
//
#define ERROR_DS_NONEXISTENT_POSS_SUP    8390L

//
// MessageId: ERROR_DS_SUB_CLS_TEST_FAIL
//
// MessageText:
//
// Schema update failed: class in subclassof list does not exist or does not satisfy hierarchy rules.
//
#define ERROR_DS_SUB_CLS_TEST_FAIL       8391L

//
// MessageId: ERROR_DS_BAD_RDN_ATT_ID_SYNTAX
//
// MessageText:
//
// Schema update failed: Rdn-Att-Id has wrong syntax.
//
#define ERROR_DS_BAD_RDN_ATT_ID_SYNTAX   8392L

//
// MessageId: ERROR_DS_EXISTS_IN_AUX_CLS
//
// MessageText:
//
// Schema deletion failed: class is used as auxiliary class.
//
#define ERROR_DS_EXISTS_IN_AUX_CLS       8393L

//
// MessageId: ERROR_DS_EXISTS_IN_SUB_CLS
//
// MessageText:
//
// Schema deletion failed: class is used as sub class.
//
#define ERROR_DS_EXISTS_IN_SUB_CLS       8394L

//
// MessageId: ERROR_DS_EXISTS_IN_POSS_SUP
//
// MessageText:
//
// Schema deletion failed: class is used as poss superior.
//
#define ERROR_DS_EXISTS_IN_POSS_SUP      8395L

//
// MessageId: ERROR_DS_RECALCSCHEMA_FAILED
//
// MessageText:
//
// Schema update failed in recalculating validation cache.
//
#define ERROR_DS_RECALCSCHEMA_FAILED     8396L

//
// MessageId: ERROR_DS_TREE_DELETE_NOT_FINISHED
//
// MessageText:
//
// The tree deletion is not finished. The request must be made again to continue deleting the tree.
//
#define ERROR_DS_TREE_DELETE_NOT_FINISHED 8397L

//
// MessageId: ERROR_DS_CANT_DELETE
//
// MessageText:
//
// The requested delete operation could not be performed.
//
#define ERROR_DS_CANT_DELETE             8398L

//
// MessageId: ERROR_DS_ATT_SCHEMA_REQ_ID
//
// MessageText:
//
// Cannot read the governs class identifier for the schema record.
//
#define ERROR_DS_ATT_SCHEMA_REQ_ID       8399L

//
// MessageId: ERROR_DS_BAD_ATT_SCHEMA_SYNTAX
//
// MessageText:
//
// The attribute schema has bad syntax.
//
#define ERROR_DS_BAD_ATT_SCHEMA_SYNTAX   8400L

//
// MessageId: ERROR_DS_CANT_CACHE_ATT
//
// MessageText:
//
// The attribute could not be cached.
//
#define ERROR_DS_CANT_CACHE_ATT          8401L

//
// MessageId: ERROR_DS_CANT_CACHE_CLASS
//
// MessageText:
//
// The class could not be cached.
//
#define ERROR_DS_CANT_CACHE_CLASS        8402L

//
// MessageId: ERROR_DS_CANT_REMOVE_ATT_CACHE
//
// MessageText:
//
// The attribute could not be removed from the cache.
//
#define ERROR_DS_CANT_REMOVE_ATT_CACHE   8403L

//
// MessageId: ERROR_DS_CANT_REMOVE_CLASS_CACHE
//
// MessageText:
//
// The class could not be removed from the cache.
//
#define ERROR_DS_CANT_REMOVE_CLASS_CACHE 8404L

//
// MessageId: ERROR_DS_CANT_RETRIEVE_DN
//
// MessageText:
//
// The distinguished name attribute could not be read.
//
#define ERROR_DS_CANT_RETRIEVE_DN        8405L

//
// MessageId: ERROR_DS_MISSING_SUPREF
//
// MessageText:
//
// No superior reference has been configured for the directory service. The directory service is therefore unable to issue referrals to objects outside this forest.
//
#define ERROR_DS_MISSING_SUPREF          8406L

//
// MessageId: ERROR_DS_CANT_RETRIEVE_INSTANCE
//
// MessageText:
//
// The instance type attribute could not be retrieved.
//
#define ERROR_DS_CANT_RETRIEVE_INSTANCE  8407L

//
// MessageId: ERROR_DS_CODE_INCONSISTENCY
//
// MessageText:
//
// An internal error has occurred.
//
#define ERROR_DS_CODE_INCONSISTENCY      8408L

//
// MessageId: ERROR_DS_DATABASE_ERROR
//
// MessageText:
//
// A database error has occurred.
//
#define ERROR_DS_DATABASE_ERROR          8409L

//
// MessageId: ERROR_DS_GOVERNSID_MISSING
//
// MessageText:
//
// The attribute GOVERNSID is missing.
//
#define ERROR_DS_GOVERNSID_MISSING       8410L

//
// MessageId: ERROR_DS_MISSING_EXPECTED_ATT
//
// MessageText:
//
// An expected attribute is missing.
//
#define ERROR_DS_MISSING_EXPECTED_ATT    8411L

//
// MessageId: ERROR_DS_NCNAME_MISSING_CR_REF
//
// MessageText:
//
// The specified naming context is missing a cross reference.
//
#define ERROR_DS_NCNAME_MISSING_CR_REF   8412L

//
// MessageId: ERROR_DS_SECURITY_CHECKING_ERROR
//
// MessageText:
//
// A security checking error has occurred.
//
#define ERROR_DS_SECURITY_CHECKING_ERROR 8413L

//
// MessageId: ERROR_DS_SCHEMA_NOT_LOADED
//
// MessageText:
//
// The schema is not loaded.
//
#define ERROR_DS_SCHEMA_NOT_LOADED       8414L

//
// MessageId: ERROR_DS_SCHEMA_ALLOC_FAILED
//
// MessageText:
//
// Schema allocation failed. Please check if the machine is running low on memory.
//
#define ERROR_DS_SCHEMA_ALLOC_FAILED     8415L

//
// MessageId: ERROR_DS_ATT_SCHEMA_REQ_SYNTAX
//
// MessageText:
//
// Failed to obtain the required syntax for the attribute schema.
//
#define ERROR_DS_ATT_SCHEMA_REQ_SYNTAX   8416L

//
// MessageId: ERROR_DS_GCVERIFY_ERROR
//
// MessageText:
//
// The global catalog verification failed. The global catalog is not available or does not support the operation. Some part of the directory is currently not available.
//
#define ERROR_DS_GCVERIFY_ERROR          8417L

//
// MessageId: ERROR_DS_DRA_SCHEMA_MISMATCH
//
// MessageText:
//
// The replication operation failed because of a schema mismatch between the servers involved.
//
#define ERROR_DS_DRA_SCHEMA_MISMATCH     8418L

//
// MessageId: ERROR_DS_CANT_FIND_DSA_OBJ
//
// MessageText:
//
// The DSA object could not be found.
//
#define ERROR_DS_CANT_FIND_DSA_OBJ       8419L

//
// MessageId: ERROR_DS_CANT_FIND_EXPECTED_NC
//
// MessageText:
//
// The naming context could not be found.
//
#define ERROR_DS_CANT_FIND_EXPECTED_NC   8420L

//
// MessageId: ERROR_DS_CANT_FIND_NC_IN_CACHE
//
// MessageText:
//
// The naming context could not be found in the cache.
//
#define ERROR_DS_CANT_FIND_NC_IN_CACHE   8421L

//
// MessageId: ERROR_DS_CANT_RETRIEVE_CHILD
//
// MessageText:
//
// The child object could not be retrieved.
//
#define ERROR_DS_CANT_RETRIEVE_CHILD     8422L

//
// MessageId: ERROR_DS_SECURITY_ILLEGAL_MODIFY
//
// MessageText:
//
// The modification was not permitted for security reasons.
//
#define ERROR_DS_SECURITY_ILLEGAL_MODIFY 8423L

//
// MessageId: ERROR_DS_CANT_REPLACE_HIDDEN_REC
//
// MessageText:
//
// The operation cannot replace the hidden record.
//
#define ERROR_DS_CANT_REPLACE_HIDDEN_REC 8424L

//
// MessageId: ERROR_DS_BAD_HIERARCHY_FILE
//
// MessageText:
//
// The hierarchy file is invalid.
//
#define ERROR_DS_BAD_HIERARCHY_FILE      8425L

//
// MessageId: ERROR_DS_BUILD_HIERARCHY_TABLE_FAILED
//
// MessageText:
//
// The attempt to build the hierarchy table failed.
//
#define ERROR_DS_BUILD_HIERARCHY_TABLE_FAILED 8426L

//
// MessageId: ERROR_DS_CONFIG_PARAM_MISSING
//
// MessageText:
//
// The directory configuration parameter is missing from the registry.
//
#define ERROR_DS_CONFIG_PARAM_MISSING    8427L

//
// MessageId: ERROR_DS_COUNTING_AB_INDICES_FAILED
//
// MessageText:
//
// The attempt to count the address book indices failed.
//
#define ERROR_DS_COUNTING_AB_INDICES_FAILED 8428L

//
// MessageId: ERROR_DS_HIERARCHY_TABLE_MALLOC_FAILED
//
// MessageText:
//
// The allocation of the hierarchy table failed.
//
#define ERROR_DS_HIERARCHY_TABLE_MALLOC_FAILED 8429L

//
// MessageId: ERROR_DS_INTERNAL_FAILURE
//
// MessageText:
//
// The directory service encountered an internal failure.
//
#define ERROR_DS_INTERNAL_FAILURE        8430L

//
// MessageId: ERROR_DS_UNKNOWN_ERROR
//
// MessageText:
//
// The directory service encountered an unknown failure.
//
#define ERROR_DS_UNKNOWN_ERROR           8431L

//
// MessageId: ERROR_DS_ROOT_REQUIRES_CLASS_TOP
//
// MessageText:
//
// A root object requires a class of 'top'.
//
#define ERROR_DS_ROOT_REQUIRES_CLASS_TOP 8432L

//
// MessageId: ERROR_DS_REFUSING_FSMO_ROLES
//
// MessageText:
//
// This directory server is shutting down, and cannot take ownership of new floating single-master operation roles.
//
#define ERROR_DS_REFUSING_FSMO_ROLES     8433L

//
// MessageId: ERROR_DS_MISSING_FSMO_SETTINGS
//
// MessageText:
//
// The directory service is missing mandatory configuration information, and is unable to determine the ownership of floating single-master operation roles.
//
#define ERROR_DS_MISSING_FSMO_SETTINGS   8434L

//
// MessageId: ERROR_DS_UNABLE_TO_SURRENDER_ROLES
//
// MessageText:
//
// The directory service was unable to transfer ownership of one or more floating single-master operation roles to other servers.
//
#define ERROR_DS_UNABLE_TO_SURRENDER_ROLES 8435L

//
// MessageId: ERROR_DS_DRA_GENERIC
//
// MessageText:
//
// The replication operation failed.
//
#define ERROR_DS_DRA_GENERIC             8436L

//
// MessageId: ERROR_DS_DRA_INVALID_PARAMETER
//
// MessageText:
//
// An invalid parameter was specified for this replication operation.
//
#define ERROR_DS_DRA_INVALID_PARAMETER   8437L

//
// MessageId: ERROR_DS_DRA_BUSY
//
// MessageText:
//
// The directory service is too busy to complete the replication operation at this time.
//
#define ERROR_DS_DRA_BUSY                8438L

//
// MessageId: ERROR_DS_DRA_BAD_DN
//
// MessageText:
//
// The distinguished name specified for this replication operation is invalid.
//
#define ERROR_DS_DRA_BAD_DN              8439L

//
// MessageId: ERROR_DS_DRA_BAD_NC
//
// MessageText:
//
// The naming context specified for this replication operation is invalid.
//
#define ERROR_DS_DRA_BAD_NC              8440L

//
// MessageId: ERROR_DS_DRA_DN_EXISTS
//
// MessageText:
//
// The distinguished name specified for this replication operation already exists.
//
#define ERROR_DS_DRA_DN_EXISTS           8441L

//
// MessageId: ERROR_DS_DRA_INTERNAL_ERROR
//
// MessageText:
//
// The replication system encountered an internal error.
//
#define ERROR_DS_DRA_INTERNAL_ERROR      8442L

//
// MessageId: ERROR_DS_DRA_INCONSISTENT_DIT
//
// MessageText:
//
// The replication operation encountered a database inconsistency.
//
#define ERROR_DS_DRA_INCONSISTENT_DIT    8443L

//
// MessageId: ERROR_DS_DRA_CONNECTION_FAILED
//
// MessageText:
//
// The server specified for this replication operation could not be contacted.
//
#define ERROR_DS_DRA_CONNECTION_FAILED   8444L

//
// MessageId: ERROR_DS_DRA_BAD_INSTANCE_TYPE
//
// MessageText:
//
// The replication operation encountered an object with an invalid instance type.
//
#define ERROR_DS_DRA_BAD_INSTANCE_TYPE   8445L

//
// MessageId: ERROR_DS_DRA_OUT_OF_MEM
//
// MessageText:
//
// The replication operation failed to allocate memory.
//
#define ERROR_DS_DRA_OUT_OF_MEM          8446L

//
// MessageId: ERROR_DS_DRA_MAIL_PROBLEM
//
// MessageText:
//
// The replication operation encountered an error with the mail system.
//
#define ERROR_DS_DRA_MAIL_PROBLEM        8447L

//
// MessageId: ERROR_DS_DRA_REF_ALREADY_EXISTS
//
// MessageText:
//
// The replication reference information for the target server already exists.
//
#define ERROR_DS_DRA_REF_ALREADY_EXISTS  8448L

//
// MessageId: ERROR_DS_DRA_REF_NOT_FOUND
//
// MessageText:
//
// The replication reference information for the target server does not exist.
//
#define ERROR_DS_DRA_REF_NOT_FOUND       8449L

//
// MessageId: ERROR_DS_DRA_OBJ_IS_REP_SOURCE
//
// MessageText:
//
// The naming context cannot be removed because it is replicated to another server.
//
#define ERROR_DS_DRA_OBJ_IS_REP_SOURCE   8450L

//
// MessageId: ERROR_DS_DRA_DB_ERROR
//
// MessageText:
//
// The replication operation encountered a database error.
//
#define ERROR_DS_DRA_DB_ERROR            8451L

//
// MessageId: ERROR_DS_DRA_NO_REPLICA
//
// MessageText:
//
// The naming context is in the process of being removed or is not replicated from the specified server.
//
#define ERROR_DS_DRA_NO_REPLICA          8452L

//
// MessageId: ERROR_DS_DRA_ACCESS_DENIED
//
// MessageText:
//
// Replication access was denied.
//
#define ERROR_DS_DRA_ACCESS_DENIED       8453L

//
// MessageId: ERROR_DS_DRA_NOT_SUPPORTED
//
// MessageText:
//
// The requested operation is not supported by this version of the directory service.
//
#define ERROR_DS_DRA_NOT_SUPPORTED       8454L

//
// MessageId: ERROR_DS_DRA_RPC_CANCELLED
//
// MessageText:
//
// The replication remote procedure call was cancelled.
//
#define ERROR_DS_DRA_RPC_CANCELLED       8455L

//
// MessageId: ERROR_DS_DRA_SOURCE_DISABLED
//
// MessageText:
//
// The source server is currently rejecting replication requests.
//
#define ERROR_DS_DRA_SOURCE_DISABLED     8456L

//
// MessageId: ERROR_DS_DRA_SINK_DISABLED
//
// MessageText:
//
// The destination server is currently rejecting replication requests.
//
#define ERROR_DS_DRA_SINK_DISABLED       8457L

//
// MessageId: ERROR_DS_DRA_NAME_COLLISION
//
// MessageText:
//
// The replication operation failed due to a collision of object names.
//
#define ERROR_DS_DRA_NAME_COLLISION      8458L

//
// MessageId: ERROR_DS_DRA_SOURCE_REINSTALLED
//
// MessageText:
//
// The replication source has been reinstalled.
//
#define ERROR_DS_DRA_SOURCE_REINSTALLED  8459L

//
// MessageId: ERROR_DS_DRA_MISSING_PARENT
//
// MessageText:
//
// The replication operation failed because a required parent object is missing.
//
#define ERROR_DS_DRA_MISSING_PARENT      8460L

//
// MessageId: ERROR_DS_DRA_PREEMPTED
//
// MessageText:
//
// The replication operation was preempted.
//
#define ERROR_DS_DRA_PREEMPTED           8461L

//
// MessageId: ERROR_DS_DRA_ABANDON_SYNC
//
// MessageText:
//
// The replication synchronization attempt was abandoned because of a lack of updates.
//
#define ERROR_DS_DRA_ABANDON_SYNC        8462L

//
// MessageId: ERROR_DS_DRA_SHUTDOWN
//
// MessageText:
//
// The replication operation was terminated because the system is shutting down.
//
#define ERROR_DS_DRA_SHUTDOWN            8463L

//
// MessageId: ERROR_DS_DRA_INCOMPATIBLE_PARTIAL_SET
//
// MessageText:
//
// Synchronization attempt failed because the destination DC is currently waiting to synchronize new partial attributes from source. This condition is normal if a recent schema change modified the partial attribute set. The destination partial attribute set is not a subset of source partial attribute set.
//
#define ERROR_DS_DRA_INCOMPATIBLE_PARTIAL_SET 8464L

//
// MessageId: ERROR_DS_DRA_SOURCE_IS_PARTIAL_REPLICA
//
// MessageText:
//
// The replication synchronization attempt failed because a master replica attempted to sync from a partial replica.
//
#define ERROR_DS_DRA_SOURCE_IS_PARTIAL_REPLICA 8465L

//
// MessageId: ERROR_DS_DRA_EXTN_CONNECTION_FAILED
//
// MessageText:
//
// The server specified for this replication operation was contacted, but that server was unable to contact an additional server needed to complete the operation.
//
#define ERROR_DS_DRA_EXTN_CONNECTION_FAILED 8466L

//
// MessageId: ERROR_DS_INSTALL_SCHEMA_MISMATCH
//
// MessageText:
//
// The version of the directory service schema of the source forest is not compatible with the version of directory service on this computer.
//
#define ERROR_DS_INSTALL_SCHEMA_MISMATCH 8467L

//
// MessageId: ERROR_DS_DUP_LINK_ID
//
// MessageText:
//
// Schema update failed: An attribute with the same link identifier already exists.
//
#define ERROR_DS_DUP_LINK_ID             8468L

//
// MessageId: ERROR_DS_NAME_ERROR_RESOLVING
//
// MessageText:
//
// Name translation: Generic processing error.
//
#define ERROR_DS_NAME_ERROR_RESOLVING    8469L

//
// MessageId: ERROR_DS_NAME_ERROR_NOT_FOUND
//
// MessageText:
//
// Name translation: Could not find the name or insufficient right to see name.
//
#define ERROR_DS_NAME_ERROR_NOT_FOUND    8470L

//
// MessageId: ERROR_DS_NAME_ERROR_NOT_UNIQUE
//
// MessageText:
//
// Name translation: Input name mapped to more than one output name.
//
#define ERROR_DS_NAME_ERROR_NOT_UNIQUE   8471L

//
// MessageId: ERROR_DS_NAME_ERROR_NO_MAPPING
//
// MessageText:
//
// Name translation: Input name found, but not the associated output format.
//
#define ERROR_DS_NAME_ERROR_NO_MAPPING   8472L

//
// MessageId: ERROR_DS_NAME_ERROR_DOMAIN_ONLY
//
// MessageText:
//
// Name translation: Unable to resolve completely, only the domain was found.
//
#define ERROR_DS_NAME_ERROR_DOMAIN_ONLY  8473L

//
// MessageId: ERROR_DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING
//
// MessageText:
//
// Name translation: Unable to perform purely syntactical mapping at the client without going out to the wire.
//
#define ERROR_DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING 8474L

//
// MessageId: ERROR_DS_CONSTRUCTED_ATT_MOD
//
// MessageText:
//
// Modification of a constructed attribute is not allowed.
//
#define ERROR_DS_CONSTRUCTED_ATT_MOD     8475L

//
// MessageId: ERROR_DS_WRONG_OM_OBJ_CLASS
//
// MessageText:
//
// The OM-Object-Class specified is incorrect for an attribute with the specified syntax.
//
#define ERROR_DS_WRONG_OM_OBJ_CLASS      8476L

//
// MessageId: ERROR_DS_DRA_REPL_PENDING
//
// MessageText:
//
// The replication request has been posted; waiting for reply.
//
#define ERROR_DS_DRA_REPL_PENDING        8477L

//
// MessageId: ERROR_DS_DS_REQUIRED
//
// MessageText:
//
// The requested operation requires a directory service, and none was available.
//
#define ERROR_DS_DS_REQUIRED             8478L

//
// MessageId: ERROR_DS_INVALID_LDAP_DISPLAY_NAME
//
// MessageText:
//
// The LDAP display name of the class or attribute contains non-ASCII characters.
//
#define ERROR_DS_INVALID_LDAP_DISPLAY_NAME 8479L

//
// MessageId: ERROR_DS_NON_BASE_SEARCH
//
// MessageText:
//
// The requested search operation is only supported for base searches.
//
#define ERROR_DS_NON_BASE_SEARCH         8480L

//
// MessageId: ERROR_DS_CANT_RETRIEVE_ATTS
//
// MessageText:
//
// The search failed to retrieve attributes from the database.
//
#define ERROR_DS_CANT_RETRIEVE_ATTS      8481L

//
// MessageId: ERROR_DS_BACKLINK_WITHOUT_LINK
//
// MessageText:
//
// The schema update operation tried to add a backward link attribute that has no corresponding forward link.
//
#define ERROR_DS_BACKLINK_WITHOUT_LINK   8482L

//
// MessageId: ERROR_DS_EPOCH_MISMATCH
//
// MessageText:
//
// Source and destination of a cross-domain move do not agree on the object's epoch number. Either source or destination does not have the latest version of the object.
//
#define ERROR_DS_EPOCH_MISMATCH          8483L

//
// MessageId: ERROR_DS_SRC_NAME_MISMATCH
//
// MessageText:
//
// Source and destination of a cross-domain move do not agree on the object's current name. Either source or destination does not have the latest version of the object.
//
#define ERROR_DS_SRC_NAME_MISMATCH       8484L

//
// MessageId: ERROR_DS_SRC_AND_DST_NC_IDENTICAL
//
// MessageText:
//
// Source and destination for the cross-domain move operation are identical. Caller should use local move operation instead of cross-domain move operation.
//
#define ERROR_DS_SRC_AND_DST_NC_IDENTICAL 8485L

//
// MessageId: ERROR_DS_DST_NC_MISMATCH
//
// MessageText:
//
// Source and destination for a cross-domain move are not in agreement on the naming contexts in the forest. Either source or destination does not have the latest version of the Partitions container.
//
#define ERROR_DS_DST_NC_MISMATCH         8486L

//
// MessageId: ERROR_DS_NOT_AUTHORITIVE_FOR_DST_NC
//
// MessageText:
//
// Destination of a cross-domain move is not authoritative for the destination naming context.
//
#define ERROR_DS_NOT_AUTHORITIVE_FOR_DST_NC 8487L

//
// MessageId: ERROR_DS_SRC_GUID_MISMATCH
//
// MessageText:
//
// Source and destination of a cross-domain move do not agree on the identity of the source object. Either source or destination does not have the latest version of the source object.
//
#define ERROR_DS_SRC_GUID_MISMATCH       8488L

//
// MessageId: ERROR_DS_CANT_MOVE_DELETED_OBJECT
//
// MessageText:
//
// Object being moved across-domains is already known to be deleted by the destination server. The source server does not have the latest version of the source object.
//
#define ERROR_DS_CANT_MOVE_DELETED_OBJECT 8489L

//
// MessageId: ERROR_DS_PDC_OPERATION_IN_PROGRESS
//
// MessageText:
//
// Another operation which requires exclusive access to the PDC FSMO is already in progress.
//
#define ERROR_DS_PDC_OPERATION_IN_PROGRESS 8490L

//
// MessageId: ERROR_DS_CROSS_DOMAIN_CLEANUP_REQD
//
// MessageText:
//
// A cross-domain move operation failed such that two versions of the moved object exist - one each in the source and destination domains. The destination object needs to be removed to restore the system to a consistent state.
//
#define ERROR_DS_CROSS_DOMAIN_CLEANUP_REQD 8491L

//
// MessageId: ERROR_DS_ILLEGAL_XDOM_MOVE_OPERATION
//
// MessageText:
//
// This object may not be moved across domain boundaries either because cross-domain moves for this class are disallowed, or the object has some special characteristics, e.g.: trust account or restricted RID, which prevent its move.
//
#define ERROR_DS_ILLEGAL_XDOM_MOVE_OPERATION 8492L

//
// MessageId: ERROR_DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS
//
// MessageText:
//
// Can't move objects with memberships across domain boundaries as once moved, this would violate the membership conditions of the account group. Remove the object from any account group memberships and retry.
//
#define ERROR_DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS 8493L

//
// MessageId: ERROR_DS_NC_MUST_HAVE_NC_PARENT
//
// MessageText:
//
// A naming context head must be the immediate child of another naming context head, not of an interior node.
//
#define ERROR_DS_NC_MUST_HAVE_NC_PARENT  8494L

//
// MessageId: ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE
//
// MessageText:
//
// The directory cannot validate the proposed naming context name because it does not hold a replica of the naming context above the proposed naming context. Please ensure that the domain naming master role is held by a server that is configured as a global catalog server, and that the server is up to date with its replication partners. (Applies only to Windows 2000 Domain Naming masters)
//
#define ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE 8495L

//
// MessageId: ERROR_DS_DST_DOMAIN_NOT_NATIVE
//
// MessageText:
//
// Destination domain must be in native mode.
//
#define ERROR_DS_DST_DOMAIN_NOT_NATIVE   8496L

//
// MessageId: ERROR_DS_MISSING_INFRASTRUCTURE_CONTAINER
//
// MessageText:
//
// The operation cannot be performed because the server does not have an infrastructure container in the domain of interest.
//
#define ERROR_DS_MISSING_INFRASTRUCTURE_CONTAINER 8497L

//
// MessageId: ERROR_DS_CANT_MOVE_ACCOUNT_GROUP
//
// MessageText:
//
// Cross-domain move of non-empty account groups is not allowed.
//
#define ERROR_DS_CANT_MOVE_ACCOUNT_GROUP 8498L

//
// MessageId: ERROR_DS_CANT_MOVE_RESOURCE_GROUP
//
// MessageText:
//
// Cross-domain move of non-empty resource groups is not allowed.
//
#define ERROR_DS_CANT_MOVE_RESOURCE_GROUP 8499L

//
// MessageId: ERROR_DS_INVALID_SEARCH_FLAG
//
// MessageText:
//
// The search flags for the attribute are invalid. The ANR bit is valid only on attributes of Unicode or Teletex strings.
//
#define ERROR_DS_INVALID_SEARCH_FLAG     8500L

//
// MessageId: ERROR_DS_NO_TREE_DELETE_ABOVE_NC
//
// MessageText:
//
// Tree deletions starting at an object which has an NC head as a descendant are not allowed.
//
#define ERROR_DS_NO_TREE_DELETE_ABOVE_NC 8501L

//
// MessageId: ERROR_DS_COULDNT_LOCK_TREE_FOR_DELETE
//
// MessageText:
//
// The directory service failed to lock a tree in preparation for a tree deletion because the tree was in use.
//
#define ERROR_DS_COULDNT_LOCK_TREE_FOR_DELETE 8502L

//
// MessageId: ERROR_DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE
//
// MessageText:
//
// The directory service failed to identify the list of objects to delete while attempting a tree deletion.
//
#define ERROR_DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE 8503L

//
// MessageId: ERROR_DS_SAM_INIT_FAILURE
//
// MessageText:
//
// Security Accounts Manager initialization failed because of the following error: %1.
// Error Status: 0x%2. Click OK to shut down the system and reboot into Directory Services Restore Mode. Check the event log for detailed information.
//
#define ERROR_DS_SAM_INIT_FAILURE        8504L

//
// MessageId: ERROR_DS_SENSITIVE_GROUP_VIOLATION
//
// MessageText:
//
// Only an administrator can modify the membership list of an administrative group.
//
#define ERROR_DS_SENSITIVE_GROUP_VIOLATION 8505L

//
// MessageId: ERROR_DS_CANT_MOD_PRIMARYGROUPID
//
// MessageText:
//
// Cannot change the primary group ID of a domain controller account.
//
#define ERROR_DS_CANT_MOD_PRIMARYGROUPID 8506L

//
// MessageId: ERROR_DS_ILLEGAL_BASE_SCHEMA_MOD
//
// MessageText:
//
// An attempt is made to modify the base schema.
//
#define ERROR_DS_ILLEGAL_BASE_SCHEMA_MOD 8507L

//
// MessageId: ERROR_DS_NONSAFE_SCHEMA_CHANGE
//
// MessageText:
//
// Adding a new mandatory attribute to an existing class, deleting a mandatory attribute from an existing class, or adding an optional attribute to the special class Top that is not a backlink attribute (directly or through inheritance, for example, by adding or deleting an auxiliary class) is not allowed.
//
#define ERROR_DS_NONSAFE_SCHEMA_CHANGE   8508L

//
// MessageId: ERROR_DS_SCHEMA_UPDATE_DISALLOWED
//
// MessageText:
//
// Schema update is not allowed on this DC because the DC is not the schema FSMO Role Owner.
//
#define ERROR_DS_SCHEMA_UPDATE_DISALLOWED 8509L

//
// MessageId: ERROR_DS_CANT_CREATE_UNDER_SCHEMA
//
// MessageText:
//
// An object of this class cannot be created under the schema container. You can only create attribute-schema and class-schema objects under the schema container.
//
#define ERROR_DS_CANT_CREATE_UNDER_SCHEMA 8510L

//
// MessageId: ERROR_DS_INSTALL_NO_SRC_SCH_VERSION
//
// MessageText:
//
// The replica/child install failed to get the objectVersion attribute on the schema container on the source DC. Either the attribute is missing on the schema container or the credentials supplied do not have permission to read it.
//
#define ERROR_DS_INSTALL_NO_SRC_SCH_VERSION 8511L

//
// MessageId: ERROR_DS_INSTALL_NO_SCH_VERSION_IN_INIFILE
//
// MessageText:
//
// The replica/child install failed to read the objectVersion attribute in the SCHEMA section of the file schema.ini in the system32 directory.
//
#define ERROR_DS_INSTALL_NO_SCH_VERSION_IN_INIFILE 8512L

//
// MessageId: ERROR_DS_INVALID_GROUP_TYPE
//
// MessageText:
//
// The specified group type is invalid.
//
#define ERROR_DS_INVALID_GROUP_TYPE      8513L

//
// MessageId: ERROR_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN
//
// MessageText:
//
// You cannot nest global groups in a mixed domain if the group is security-enabled.
//
#define ERROR_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN 8514L

//
// MessageId: ERROR_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN
//
// MessageText:
//
// You cannot nest local groups in a mixed domain if the group is security-enabled.
//
#define ERROR_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN 8515L

//
// MessageId: ERROR_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER
//
// MessageText:
//
// A global group cannot have a local group as a member.
//
#define ERROR_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER 8516L

//
// MessageId: ERROR_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER
//
// MessageText:
//
// A global group cannot have a universal group as a member.
//
#define ERROR_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER 8517L

//
// MessageId: ERROR_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER
//
// MessageText:
//
// A universal group cannot have a local group as a member.
//
#define ERROR_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER 8518L

//
// MessageId: ERROR_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER
//
// MessageText:
//
// A global group cannot have a cross-domain member.
//
#define ERROR_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER 8519L

//
// MessageId: ERROR_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER
//
// MessageText:
//
// A local group cannot have another cross domain local group as a member.
//
#define ERROR_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER 8520L

//
// MessageId: ERROR_DS_HAVE_PRIMARY_MEMBERS
//
// MessageText:
//
// A group with primary members cannot change to a security-disabled group.
//
#define ERROR_DS_HAVE_PRIMARY_MEMBERS    8521L

//
// MessageId: ERROR_DS_STRING_SD_CONVERSION_FAILED
//
// MessageText:
//
// The schema cache load failed to convert the string default SD on a class-schema object.
//
#define ERROR_DS_STRING_SD_CONVERSION_FAILED 8522L

//
// MessageId: ERROR_DS_NAMING_MASTER_GC
//
// MessageText:
//
// Only DSAs configured to be Global Catalog servers should be allowed to hold the Domain Naming Master FSMO role. (Applies only to Windows 2000 servers)
//
#define ERROR_DS_NAMING_MASTER_GC        8523L

//
// MessageId: ERROR_DS_DNS_LOOKUP_FAILURE
//
// MessageText:
//
// The DSA operation is unable to proceed because of a DNS lookup failure.
//
#define ERROR_DS_DNS_LOOKUP_FAILURE      8524L

//
// MessageId: ERROR_DS_COULDNT_UPDATE_SPNS
//
// MessageText:
//
// While processing a change to the DNS Host Name for an object, the Service Principal Name values could not be kept in sync.
//
#define ERROR_DS_COULDNT_UPDATE_SPNS     8525L

//
// MessageId: ERROR_DS_CANT_RETRIEVE_SD
//
// MessageText:
//
// The Security Descriptor attribute could not be read.
//
#define ERROR_DS_CANT_RETRIEVE_SD        8526L

//
// MessageId: ERROR_DS_KEY_NOT_UNIQUE
//
// MessageText:
//
// The object requested was not found, but an object with that key was found.
//
#define ERROR_DS_KEY_NOT_UNIQUE          8527L

//
// MessageId: ERROR_DS_WRONG_LINKED_ATT_SYNTAX
//
// MessageText:
//
// The syntax of the linked attribute being added is incorrect. Forward links can only have syntax 2.5.5.1, 2.5.5.7, and 2.5.5.14, and backlinks can only have syntax 2.5.5.1
//
#define ERROR_DS_WRONG_LINKED_ATT_SYNTAX 8528L

//
// MessageId: ERROR_DS_SAM_NEED_BOOTKEY_PASSWORD
//
// MessageText:
//
// Security Account Manager needs to get the boot password.
//
#define ERROR_DS_SAM_NEED_BOOTKEY_PASSWORD 8529L

//
// MessageId: ERROR_DS_SAM_NEED_BOOTKEY_FLOPPY
//
// MessageText:
//
// Security Account Manager needs to get the boot key from floppy disk.
//
#define ERROR_DS_SAM_NEED_BOOTKEY_FLOPPY 8530L

//
// MessageId: ERROR_DS_CANT_START
//
// MessageText:
//
// Directory Service cannot start.
//
#define ERROR_DS_CANT_START              8531L

//
// MessageId: ERROR_DS_INIT_FAILURE
//
// MessageText:
//
// Directory Services could not start.
//
#define ERROR_DS_INIT_FAILURE            8532L

//
// MessageId: ERROR_DS_NO_PKT_PRIVACY_ON_CONNECTION
//
// MessageText:
//
// The connection between client and server requires packet privacy or better.
//
#define ERROR_DS_NO_PKT_PRIVACY_ON_CONNECTION 8533L

//
// MessageId: ERROR_DS_SOURCE_DOMAIN_IN_FOREST
//
// MessageText:
//
// The source domain may not be in the same forest as destination.
//
#define ERROR_DS_SOURCE_DOMAIN_IN_FOREST 8534L

//
// MessageId: ERROR_DS_DESTINATION_DOMAIN_NOT_IN_FOREST
//
// MessageText:
//
// The destination domain must be in the forest.
//
#define ERROR_DS_DESTINATION_DOMAIN_NOT_IN_FOREST 8535L

//
// MessageId: ERROR_DS_DESTINATION_AUDITING_NOT_ENABLED
//
// MessageText:
//
// The operation requires that destination domain auditing be enabled.
//
#define ERROR_DS_DESTINATION_AUDITING_NOT_ENABLED 8536L

//
// MessageId: ERROR_DS_CANT_FIND_DC_FOR_SRC_DOMAIN
//
// MessageText:
//
// The operation couldn't locate a DC for the source domain.
//
#define ERROR_DS_CANT_FIND_DC_FOR_SRC_DOMAIN 8537L

//
// MessageId: ERROR_DS_SRC_OBJ_NOT_GROUP_OR_USER
//
// MessageText:
//
// The source object must be a group or user.
//
#define ERROR_DS_SRC_OBJ_NOT_GROUP_OR_USER 8538L

//
// MessageId: ERROR_DS_SRC_SID_EXISTS_IN_FOREST
//
// MessageText:
//
// The source object's SID already exists in destination forest.
//
#define ERROR_DS_SRC_SID_EXISTS_IN_FOREST 8539L

//
// MessageId: ERROR_DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH
//
// MessageText:
//
// The source and destination object must be of the same type.
//
#define ERROR_DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH 8540L

//
// MessageId: ERROR_SAM_INIT_FAILURE
//
// MessageText:
//
// Security Accounts Manager initialization failed because of the following error: %1.
// Error Status: 0x%2. Click OK to shut down the system and reboot into Safe Mode. Check the event log for detailed information.
//
#define ERROR_SAM_INIT_FAILURE           8541L

//
// MessageId: ERROR_DS_DRA_SCHEMA_INFO_SHIP
//
// MessageText:
//
// Schema information could not be included in the replication request.
//
#define ERROR_DS_DRA_SCHEMA_INFO_SHIP    8542L

//
// MessageId: ERROR_DS_DRA_SCHEMA_CONFLICT
//
// MessageText:
//
// The replication operation could not be completed due to a schema incompatibility.
//
#define ERROR_DS_DRA_SCHEMA_CONFLICT     8543L

//
// MessageId: ERROR_DS_DRA_EARLIER_SCHEMA_CONFLICT
//
// MessageText:
//
// The replication operation could not be completed due to a previous schema incompatibility.
//
#define ERROR_DS_DRA_EARLIER_SCHEMA_CONFLICT 8544L

//
// MessageId: ERROR_DS_DRA_OBJ_NC_MISMATCH
//
// MessageText:
//
// The replication update could not be applied because either the source or the destination has not yet received information regarding a recent cross-domain move operation.
//
#define ERROR_DS_DRA_OBJ_NC_MISMATCH     8545L

//
// MessageId: ERROR_DS_NC_STILL_HAS_DSAS
//
// MessageText:
//
// The requested domain could not be deleted because there exist domain controllers that still host this domain.
//
#define ERROR_DS_NC_STILL_HAS_DSAS       8546L

//
// MessageId: ERROR_DS_GC_REQUIRED
//
// MessageText:
//
// The requested operation can be performed only on a global catalog server.
//
#define ERROR_DS_GC_REQUIRED             8547L

//
// MessageId: ERROR_DS_LOCAL_MEMBER_OF_LOCAL_ONLY
//
// MessageText:
//
// A local group can only be a member of other local groups in the same domain.
//
#define ERROR_DS_LOCAL_MEMBER_OF_LOCAL_ONLY 8548L

//
// MessageId: ERROR_DS_NO_FPO_IN_UNIVERSAL_GROUPS
//
// MessageText:
//
// Foreign security principals cannot be members of universal groups.
//
#define ERROR_DS_NO_FPO_IN_UNIVERSAL_GROUPS 8549L

//
// MessageId: ERROR_DS_CANT_ADD_TO_GC
//
// MessageText:
//
// The attribute is not allowed to be replicated to the GC because of security reasons.
//
#define ERROR_DS_CANT_ADD_TO_GC          8550L

//
// MessageId: ERROR_DS_NO_CHECKPOINT_WITH_PDC
//
// MessageText:
//
// The checkpoint with the PDC could not be taken because there too many modifications being processed currently.
//
#define ERROR_DS_NO_CHECKPOINT_WITH_PDC  8551L

//
// MessageId: ERROR_DS_SOURCE_AUDITING_NOT_ENABLED
//
// MessageText:
//
// The operation requires that source domain auditing be enabled.
//
#define ERROR_DS_SOURCE_AUDITING_NOT_ENABLED 8552L

//
// MessageId: ERROR_DS_CANT_CREATE_IN_NONDOMAIN_NC
//
// MessageText:
//
// Security principal objects can only be created inside domain naming contexts.
//
#define ERROR_DS_CANT_CREATE_IN_NONDOMAIN_NC 8553L

//
// MessageId: ERROR_DS_INVALID_NAME_FOR_SPN
//
// MessageText:
//
// A Service Principal Name (SPN) could not be constructed because the provided hostname is not in the necessary format.
//
#define ERROR_DS_INVALID_NAME_FOR_SPN    8554L

//
// MessageId: ERROR_DS_FILTER_USES_CONTRUCTED_ATTRS
//
// MessageText:
//
// A Filter was passed that uses constructed attributes.
//
#define ERROR_DS_FILTER_USES_CONTRUCTED_ATTRS 8555L

//
// MessageId: ERROR_DS_UNICODEPWD_NOT_IN_QUOTES
//
// MessageText:
//
// The unicodePwd attribute value must be enclosed in double quotes.
//
#define ERROR_DS_UNICODEPWD_NOT_IN_QUOTES 8556L

//
// MessageId: ERROR_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED
//
// MessageText:
//
// Your computer could not be joined to the domain. You have exceeded the maximum number of computer accounts you are allowed to create in this domain. Contact your system administrator to have this limit reset or increased.
//
#define ERROR_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED 8557L

//
// MessageId: ERROR_DS_MUST_BE_RUN_ON_DST_DC
//
// MessageText:
//
// For security reasons, the operation must be run on the destination DC.
//
#define ERROR_DS_MUST_BE_RUN_ON_DST_DC   8558L

//
// MessageId: ERROR_DS_SRC_DC_MUST_BE_SP4_OR_GREATER
//
// MessageText:
//
// For security reasons, the source DC must be NT4SP4 or greater.
//
#define ERROR_DS_SRC_DC_MUST_BE_SP4_OR_GREATER 8559L

//
// MessageId: ERROR_DS_CANT_TREE_DELETE_CRITICAL_OBJ
//
// MessageText:
//
// Critical Directory Service System objects cannot be deleted during tree delete operations. The tree delete may have been partially performed.
//
#define ERROR_DS_CANT_TREE_DELETE_CRITICAL_OBJ 8560L

//
// MessageId: ERROR_DS_INIT_FAILURE_CONSOLE
//
// MessageText:
//
// Directory Services could not start because of the following error: %1.
// Error Status: 0x%2. Please click OK to shutdown the system. You can use the recovery console to diagnose the system further.
//
#define ERROR_DS_INIT_FAILURE_CONSOLE    8561L

//
// MessageId: ERROR_DS_SAM_INIT_FAILURE_CONSOLE
//
// MessageText:
//
// Security Accounts Manager initialization failed because of the following error: %1.
// Error Status: 0x%2. Please click OK to shutdown the system. You can use the recovery console to diagnose the system further.
//
#define ERROR_DS_SAM_INIT_FAILURE_CONSOLE 8562L

//
// MessageId: ERROR_DS_FOREST_VERSION_TOO_HIGH
//
// MessageText:
//
// The version of the operating system installed is incompatible with the current forest functional level. You must upgrade to a new version of the operating system before this server can become a domain controller in this forest.
//
#define ERROR_DS_FOREST_VERSION_TOO_HIGH 8563L

//
// MessageId: ERROR_DS_DOMAIN_VERSION_TOO_HIGH
//
// MessageText:
//
// The version of the operating system installed is incompatible with the current domain functional level. You must upgrade to a new version of the operating system before this server can become a domain controller in this domain.
//
#define ERROR_DS_DOMAIN_VERSION_TOO_HIGH 8564L

//
// MessageId: ERROR_DS_FOREST_VERSION_TOO_LOW
//
// MessageText:
//
// The version of the operating system installed on this server no longer supports the current forest functional level. You must raise the forest functional level before this server can become a domain controller in this forest.
//
#define ERROR_DS_FOREST_VERSION_TOO_LOW  8565L

//
// MessageId: ERROR_DS_DOMAIN_VERSION_TOO_LOW
//
// MessageText:
//
// The version of the operating system installed on this server no longer supports the current domain functional level. You must raise the domain functional level before this server can become a domain controller in this domain.
//
#define ERROR_DS_DOMAIN_VERSION_TOO_LOW  8566L

//
// MessageId: ERROR_DS_INCOMPATIBLE_VERSION
//
// MessageText:
//
// The version of the operating system installed on this server is incompatible with the functional level of the domain or forest.
//
#define ERROR_DS_INCOMPATIBLE_VERSION    8567L

//
// MessageId: ERROR_DS_LOW_DSA_VERSION
//
// MessageText:
//
// The functional level of the domain (or forest) cannot be raised to the requested value, because there exist one or more domain controllers in the domain (or forest) that are at a lower incompatible functional level.
//
#define ERROR_DS_LOW_DSA_VERSION         8568L

//
// MessageId: ERROR_DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN
//
// MessageText:
//
// The forest functional level cannot be raised to the requested value since one or more domains are still in mixed domain mode. All domains in the forest must be in native mode, for you to raise the forest functional level.
//
#define ERROR_DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN 8569L

//
// MessageId: ERROR_DS_NOT_SUPPORTED_SORT_ORDER
//
// MessageText:
//
// The sort order requested is not supported.
//
#define ERROR_DS_NOT_SUPPORTED_SORT_ORDER 8570L

//
// MessageId: ERROR_DS_NAME_NOT_UNIQUE
//
// MessageText:
//
// The requested name already exists as a unique identifier.
//
#define ERROR_DS_NAME_NOT_UNIQUE         8571L

//
// MessageId: ERROR_DS_MACHINE_ACCOUNT_CREATED_PRENT4
//
// MessageText:
//
// The machine account was created pre-NT4. The account needs to be recreated.
//
#define ERROR_DS_MACHINE_ACCOUNT_CREATED_PRENT4 8572L

//
// MessageId: ERROR_DS_OUT_OF_VERSION_STORE
//
// MessageText:
//
// The database is out of version store.
//
#define ERROR_DS_OUT_OF_VERSION_STORE    8573L

//
// MessageId: ERROR_DS_INCOMPATIBLE_CONTROLS_USED
//
// MessageText:
//
// Unable to continue operation because multiple conflicting controls were used.
//
#define ERROR_DS_INCOMPATIBLE_CONTROLS_USED 8574L

//
// MessageId: ERROR_DS_NO_REF_DOMAIN
//
// MessageText:
//
// Unable to find a valid security descriptor reference domain for this partition.
//
#define ERROR_DS_NO_REF_DOMAIN           8575L

//
// MessageId: ERROR_DS_RESERVED_LINK_ID
//
// MessageText:
//
// Schema update failed: The link identifier is reserved.
//
#define ERROR_DS_RESERVED_LINK_ID        8576L

//
// MessageId: ERROR_DS_LINK_ID_NOT_AVAILABLE
//
// MessageText:
//
// Schema update failed: There are no link identifiers available.
//
#define ERROR_DS_LINK_ID_NOT_AVAILABLE   8577L

//
// MessageId: ERROR_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER
//
// MessageText:
//
// An account group cannot have a universal group as a member.
//
#define ERROR_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER 8578L

//
// MessageId: ERROR_DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE
//
// MessageText:
//
// Rename or move operations on naming context heads or read-only objects are not allowed.
//
#define ERROR_DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE 8579L

//
// MessageId: ERROR_DS_NO_OBJECT_MOVE_IN_SCHEMA_NC
//
// MessageText:
//
// Move operations on objects in the schema naming context are not allowed.
//
#define ERROR_DS_NO_OBJECT_MOVE_IN_SCHEMA_NC 8580L

//
// MessageId: ERROR_DS_MODIFYDN_DISALLOWED_BY_FLAG
//
// MessageText:
//
// A system flag has been set on the object and does not allow the object to be moved or renamed.
//
#define ERROR_DS_MODIFYDN_DISALLOWED_BY_FLAG 8581L

//
// MessageId: ERROR_DS_MODIFYDN_WRONG_GRANDPARENT
//
// MessageText:
//
// This object is not allowed to change its grandparent container. Moves are not forbidden on this object, but are restricted to sibling containers.
//
#define ERROR_DS_MODIFYDN_WRONG_GRANDPARENT 8582L

//
// MessageId: ERROR_DS_NAME_ERROR_TRUST_REFERRAL
//
// MessageText:
//
// Unable to resolve completely, a referral to another forest is generated.
//
#define ERROR_DS_NAME_ERROR_TRUST_REFERRAL 8583L

//
// MessageId: ERROR_NOT_SUPPORTED_ON_STANDARD_SERVER
//
// MessageText:
//
// The requested action is not supported on standard server.
//
#define ERROR_NOT_SUPPORTED_ON_STANDARD_SERVER 8584L

//
// MessageId: ERROR_DS_CANT_ACCESS_REMOTE_PART_OF_AD
//
// MessageText:
//
// Could not access a partition of the directory service located on a remote server. Make sure at least one server is running for the partition in question.
//
#define ERROR_DS_CANT_ACCESS_REMOTE_PART_OF_AD 8585L

//
// MessageId: ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE_V2
//
// MessageText:
//
// The directory cannot validate the proposed naming context (or partition) name because it does not hold a replica nor can it contact a replica of the naming context above the proposed naming context. Please ensure that the parent naming context is properly registered in DNS, and at least one replica of this naming context is reachable by the Domain Naming master.
//
#define ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE_V2 8586L

//
// MessageId: ERROR_DS_THREAD_LIMIT_EXCEEDED
//
// MessageText:
//
// The thread limit for this request was exceeded.
//
#define ERROR_DS_THREAD_LIMIT_EXCEEDED   8587L

//
// MessageId: ERROR_DS_NOT_CLOSEST
//
// MessageText:
//
// The Global catalog server is not in the closest site.
//
#define ERROR_DS_NOT_CLOSEST             8588L

//
// MessageId: ERROR_DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF
//
// MessageText:
//
// The DS cannot derive a service principal name (SPN) with which to mutually authenticate the target server because the corresponding server object in the local DS database has no serverReference attribute.
//
#define ERROR_DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF 8589L

//
// MessageId: ERROR_DS_SINGLE_USER_MODE_FAILED
//
// MessageText:
//
// The Directory Service failed to enter single user mode.
//
#define ERROR_DS_SINGLE_USER_MODE_FAILED 8590L

//
// MessageId: ERROR_DS_NTDSCRIPT_SYNTAX_ERROR
//
// MessageText:
//
// The Directory Service cannot parse the script because of a syntax error.
//
#define ERROR_DS_NTDSCRIPT_SYNTAX_ERROR  8591L

//
// MessageId: ERROR_DS_NTDSCRIPT_PROCESS_ERROR
//
// MessageText:
//
// The Directory Service cannot process the script because of an error.
//
#define ERROR_DS_NTDSCRIPT_PROCESS_ERROR 8592L

//
// MessageId: ERROR_DS_DIFFERENT_REPL_EPOCHS
//
// MessageText:
//
// The directory service cannot perform the requested operation because the servers
// involved are of different replication epochs (which is usually related to a
// domain rename that is in progress).
//
#define ERROR_DS_DIFFERENT_REPL_EPOCHS   8593L

//
// MessageId: ERROR_DS_DRS_EXTENSIONS_CHANGED
//
// MessageText:
//
// The directory service binding must be renegotiated due to a change in the server
// extensions information.
//
#define ERROR_DS_DRS_EXTENSIONS_CHANGED  8594L

//
// MessageId: ERROR_DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR
//
// MessageText:
//
// Operation not allowed on a disabled cross ref.
//
#define ERROR_DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR 8595L

//
// MessageId: ERROR_DS_NO_MSDS_INTID
//
// MessageText:
//
// Schema update failed: No values for msDS-IntId are available.
//
#define ERROR_DS_NO_MSDS_INTID           8596L

//
// MessageId: ERROR_DS_DUP_MSDS_INTID
//
// MessageText:
//
// Schema update failed: Duplicate msDS-INtId. Retry the operation.
//
#define ERROR_DS_DUP_MSDS_INTID          8597L

//
// MessageId: ERROR_DS_EXISTS_IN_RDNATTID
//
// MessageText:
//
// Schema deletion failed: attribute is used in rDNAttID.
//
#define ERROR_DS_EXISTS_IN_RDNATTID      8598L

//
// MessageId: ERROR_DS_AUTHORIZATION_FAILED
//
// MessageText:
//
// The directory service failed to authorize the request.
//
#define ERROR_DS_AUTHORIZATION_FAILED    8599L

//
// MessageId: ERROR_DS_INVALID_SCRIPT
//
// MessageText:
//
// The Directory Service cannot process the script because it is invalid.
//
#define ERROR_DS_INVALID_SCRIPT          8600L

//
// MessageId: ERROR_DS_REMOTE_CROSSREF_OP_FAILED
//
// MessageText:
//
// The remote create cross reference operation failed on the Domain Naming Master FSMO. The operation's error is in the extended data.
//
#define ERROR_DS_REMOTE_CROSSREF_OP_FAILED 8601L

//
// MessageId: ERROR_DS_CROSS_REF_BUSY
//
// MessageText:
//
// A cross reference is in use locally with the same name.
//
#define ERROR_DS_CROSS_REF_BUSY          8602L

//
// MessageId: ERROR_DS_CANT_DERIVE_SPN_FOR_DELETED_DOMAIN
//
// MessageText:
//
// The DS cannot derive a service principal name (SPN) with which to mutually authenticate the target server because the server's domain has been deleted from the forest.
//
#define ERROR_DS_CANT_DERIVE_SPN_FOR_DELETED_DOMAIN 8603L

//
// MessageId: ERROR_DS_CANT_DEMOTE_WITH_WRITEABLE_NC
//
// MessageText:
//
// Writeable NCs prevent this DC from demoting.
//
#define ERROR_DS_CANT_DEMOTE_WITH_WRITEABLE_NC 8604L

//
// MessageId: ERROR_DS_DUPLICATE_ID_FOUND
//
// MessageText:
//
// The requested object has a non-unique identifier and cannot be retrieved.
//
#define ERROR_DS_DUPLICATE_ID_FOUND      8605L

//
// MessageId: ERROR_DS_INSUFFICIENT_ATTR_TO_CREATE_OBJECT
//
// MessageText:
//
// Insufficient attributes were given to create an object. This object may not exist because it may have been deleted and already garbage collected.
//
#define ERROR_DS_INSUFFICIENT_ATTR_TO_CREATE_OBJECT 8606L

//
// MessageId: ERROR_DS_GROUP_CONVERSION_ERROR
//
// MessageText:
//
// The group cannot be converted due to attribute restrictions on the requested group type.
//
#define ERROR_DS_GROUP_CONVERSION_ERROR  8607L

//
// MessageId: ERROR_DS_CANT_MOVE_APP_BASIC_GROUP
//
// MessageText:
//
// Cross-domain move of non-empty basic application groups is not allowed.
//
#define ERROR_DS_CANT_MOVE_APP_BASIC_GROUP 8608L

//
// MessageId: ERROR_DS_CANT_MOVE_APP_QUERY_GROUP
//
// MessageText:
//
// Cross-domain move of non-empty query based application groups is not allowed.
//
#define ERROR_DS_CANT_MOVE_APP_QUERY_GROUP 8609L

//
// MessageId: ERROR_DS_ROLE_NOT_VERIFIED
//
// MessageText:
//
// The FSMO role ownership could not be verified because its directory partition has not replicated successfully with atleast one replication partner.
//
#define ERROR_DS_ROLE_NOT_VERIFIED       8610L

//
// MessageId: ERROR_DS_WKO_CONTAINER_CANNOT_BE_SPECIAL
//
// MessageText:
//
// The target container for a redirection of a well known object container cannot already be a special container.
//
#define ERROR_DS_WKO_CONTAINER_CANNOT_BE_SPECIAL 8611L

//
// MessageId: ERROR_DS_DOMAIN_RENAME_IN_PROGRESS
//
// MessageText:
//
// The Directory Service cannot perform the requested operation because a domain rename operation is in progress.
//
#define ERROR_DS_DOMAIN_RENAME_IN_PROGRESS 8612L

//
// MessageId: ERROR_DS_EXISTING_AD_CHILD_NC
//
// MessageText:
//
// The directory service detected a child partition below the requested partition name. The partition hierarchy must be created in a top down method.
//
#define ERROR_DS_EXISTING_AD_CHILD_NC    8613L

//
// MessageId: ERROR_DS_REPL_LIFETIME_EXCEEDED
//
// MessageText:
//
// The directory service cannot replicate with this server because the time since the last replication with this server has exceeded the tombstone lifetime.
//
#define ERROR_DS_REPL_LIFETIME_EXCEEDED  8614L

//
// MessageId: ERROR_DS_DISALLOWED_IN_SYSTEM_CONTAINER
//
// MessageText:
//
// The requested operation is not allowed on an object under the system container.
//
#define ERROR_DS_DISALLOWED_IN_SYSTEM_CONTAINER 8615L

//
// MessageId: ERROR_DS_LDAP_SEND_QUEUE_FULL
//
// MessageText:
//
// The LDAP servers network send queue has filled up because the client is not processing the results of it's requests fast enough. No more requests will be processed until the client catches up. If the client does not catch up then it will be disconnected.
//
#define ERROR_DS_LDAP_SEND_QUEUE_FULL    8616L

//
// MessageId: ERROR_DS_DRA_OUT_SCHEDULE_WINDOW
//
// MessageText:
//
// The scheduled replication did not take place because the system was too busy to execute the request within the schedule window. The replication queue is overloaded. Consider reducing the number of partners or decreasing the scheduled replication frequency.
//
#define ERROR_DS_DRA_OUT_SCHEDULE_WINDOW 8617L

//
// MessageId: ERROR_DS_POLICY_NOT_KNOWN
//
// MessageText:
//
// At this time, it cannot be determined if the branch replication policy is available on the hub domain controller. Please retry at a later time to account for replication latencies.
//
#define ERROR_DS_POLICY_NOT_KNOWN        8618L

//
// MessageId: ERROR_NO_SITE_SETTINGS_OBJECT
//
// MessageText:
//
// The site settings object for the specified site does not exist.
//
#define ERROR_NO_SITE_SETTINGS_OBJECT    8619L

//
// MessageId: ERROR_NO_SECRETS
//
// MessageText:
//
// The local account store does not contain secret material for the specified account.
//
#define ERROR_NO_SECRETS                 8620L

//
// MessageId: ERROR_NO_WRITABLE_DC_FOUND
//
// MessageText:
//
// Could not find a writable domain controller in the domain.
//
#define ERROR_NO_WRITABLE_DC_FOUND       8621L

//
// MessageId: ERROR_DS_NO_SERVER_OBJECT
//
// MessageText:
//
// The server object for the domain controller does not exist.
//
#define ERROR_DS_NO_SERVER_OBJECT        8622L

//
// MessageId: ERROR_DS_NO_NTDSA_OBJECT
//
// MessageText:
//
// The NTDS Settings object for the domain controller does not exist.
//
#define ERROR_DS_NO_NTDSA_OBJECT         8623L

//
// MessageId: ERROR_DS_NON_ASQ_SEARCH
//
// MessageText:
//
// The requested search operation is not supported for ASQ searches.
//
#define ERROR_DS_NON_ASQ_SEARCH          8624L

//
// MessageId: ERROR_DS_AUDIT_FAILURE
//
// MessageText:
//
// A required audit event could not be generated for the operation.
//
#define ERROR_DS_AUDIT_FAILURE           8625L

//
// MessageId: ERROR_DS_INVALID_SEARCH_FLAG_SUBTREE
//
// MessageText:
//
// The search flags for the attribute are invalid. The subtree index bit is valid only on single valued attributes.
//
#define ERROR_DS_INVALID_SEARCH_FLAG_SUBTREE 8626L

//
// MessageId: ERROR_DS_INVALID_SEARCH_FLAG_TUPLE
//
// MessageText:
//
// The search flags for the attribute are invalid. The tuple index bit is valid only on attributes of Unicode strings.
//
#define ERROR_DS_INVALID_SEARCH_FLAG_TUPLE 8627L

//
// MessageId: ERROR_DS_HIERARCHY_TABLE_TOO_DEEP
//
// MessageText:
//
// The address books are nested too deeply. Failed to build the hierarchy table.
//
#define ERROR_DS_HIERARCHY_TABLE_TOO_DEEP 8628L

//
// MessageId: ERROR_DS_DRA_CORRUPT_UTD_VECTOR
//
// MessageText:
//
// The specified up-to-date-ness vector is corrupt.
//
#define ERROR_DS_DRA_CORRUPT_UTD_VECTOR  8629L

//
// MessageId: ERROR_DS_DRA_SECRETS_DENIED
//
// MessageText:
//
// The request to replicate secrets is denied.
//
#define ERROR_DS_DRA_SECRETS_DENIED      8630L

//
// MessageId: ERROR_DS_RESERVED_MAPI_ID
//
// MessageText:
//
// Schema update failed: The MAPI identifier is reserved.
//
#define ERROR_DS_RESERVED_MAPI_ID        8631L

//
// MessageId: ERROR_DS_MAPI_ID_NOT_AVAILABLE
//
// MessageText:
//
// Schema update failed: There are no MAPI identifiers available.
//
#define ERROR_DS_MAPI_ID_NOT_AVAILABLE   8632L


///////////////////////////////////////////////////
//                                                /
//        End of Active Directory Error Codes     /
//                                                /
//                  8000 to  8999                 /
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//                                               //
//               DNS Error codes                 //
//                                               //
//                 9000 to 9999                  //
///////////////////////////////////////////////////

// =============================
// Facility DNS Error Messages
// =============================

//
//  DNS response codes.
//

#define DNS_ERROR_RESPONSE_CODES_BASE 9000

#define DNS_ERROR_RCODE_NO_ERROR NO_ERROR

#define DNS_ERROR_MASK 0x00002328 // 9000 or DNS_ERROR_RESPONSE_CODES_BASE

// DNS_ERROR_RCODE_FORMAT_ERROR          0x00002329
//
// MessageId: DNS_ERROR_RCODE_FORMAT_ERROR
//
// MessageText:
//
// DNS server unable to interpret format.
//
#define DNS_ERROR_RCODE_FORMAT_ERROR     9001L

// DNS_ERROR_RCODE_SERVER_FAILURE        0x0000232a
//
// MessageId: DNS_ERROR_RCODE_SERVER_FAILURE
//
// MessageText:
//
// DNS server failure.
//
#define DNS_ERROR_RCODE_SERVER_FAILURE   9002L

// DNS_ERROR_RCODE_NAME_ERROR            0x0000232b
//
// MessageId: DNS_ERROR_RCODE_NAME_ERROR
//
// MessageText:
//
// DNS name does not exist.
//
#define DNS_ERROR_RCODE_NAME_ERROR       9003L

// DNS_ERROR_RCODE_NOT_IMPLEMENTED       0x0000232c
//
// MessageId: DNS_ERROR_RCODE_NOT_IMPLEMENTED
//
// MessageText:
//
// DNS request not supported by name server.
//
#define DNS_ERROR_RCODE_NOT_IMPLEMENTED  9004L

// DNS_ERROR_RCODE_REFUSED               0x0000232d
//
// MessageId: DNS_ERROR_RCODE_REFUSED
//
// MessageText:
//
// DNS operation refused.
//
#define DNS_ERROR_RCODE_REFUSED          9005L

// DNS_ERROR_RCODE_YXDOMAIN              0x0000232e
//
// MessageId: DNS_ERROR_RCODE_YXDOMAIN
//
// MessageText:
//
// DNS name that ought not exist, does exist.
//
#define DNS_ERROR_RCODE_YXDOMAIN         9006L

// DNS_ERROR_RCODE_YXRRSET               0x0000232f
//
// MessageId: DNS_ERROR_RCODE_YXRRSET
//
// MessageText:
//
// DNS RR set that ought not exist, does exist.
//
#define DNS_ERROR_RCODE_YXRRSET          9007L

// DNS_ERROR_RCODE_NXRRSET               0x00002330
//
// MessageId: DNS_ERROR_RCODE_NXRRSET
//
// MessageText:
//
// DNS RR set that ought to exist, does not exist.
//
#define DNS_ERROR_RCODE_NXRRSET          9008L

// DNS_ERROR_RCODE_NOTAUTH               0x00002331
//
// MessageId: DNS_ERROR_RCODE_NOTAUTH
//
// MessageText:
//
// DNS server not authoritative for zone.
//
#define DNS_ERROR_RCODE_NOTAUTH          9009L

// DNS_ERROR_RCODE_NOTZONE               0x00002332
//
// MessageId: DNS_ERROR_RCODE_NOTZONE
//
// MessageText:
//
// DNS name in update or prereq is not in zone.
//
#define DNS_ERROR_RCODE_NOTZONE          9010L

// DNS_ERROR_RCODE_BADSIG                0x00002338
//
// MessageId: DNS_ERROR_RCODE_BADSIG
//
// MessageText:
//
// DNS signature failed to verify.
//
#define DNS_ERROR_RCODE_BADSIG           9016L

// DNS_ERROR_RCODE_BADKEY                0x00002339
//
// MessageId: DNS_ERROR_RCODE_BADKEY
//
// MessageText:
//
// DNS bad key.
//
#define DNS_ERROR_RCODE_BADKEY           9017L

// DNS_ERROR_RCODE_BADTIME               0x0000233a
//
// MessageId: DNS_ERROR_RCODE_BADTIME
//
// MessageText:
//
// DNS signature validity expired.
//
#define DNS_ERROR_RCODE_BADTIME          9018L

#define DNS_ERROR_RCODE_LAST DNS_ERROR_RCODE_BADTIME


//
//  Packet format
//

#define DNS_ERROR_PACKET_FMT_BASE 9500

// DNS_INFO_NO_RECORDS                   0x0000251d
//
// MessageId: DNS_INFO_NO_RECORDS
//
// MessageText:
//
// No records found for given DNS query.
//
#define DNS_INFO_NO_RECORDS              9501L

// DNS_ERROR_BAD_PACKET                  0x0000251e
//
// MessageId: DNS_ERROR_BAD_PACKET
//
// MessageText:
//
// Bad DNS packet.
//
#define DNS_ERROR_BAD_PACKET             9502L

// DNS_ERROR_NO_PACKET                   0x0000251f
//
// MessageId: DNS_ERROR_NO_PACKET
//
// MessageText:
//
// No DNS packet.
//
#define DNS_ERROR_NO_PACKET              9503L

// DNS_ERROR_RCODE                       0x00002520
//
// MessageId: DNS_ERROR_RCODE
//
// MessageText:
//
// DNS error, check rcode.
//
#define DNS_ERROR_RCODE                  9504L

// DNS_ERROR_UNSECURE_PACKET             0x00002521
//
// MessageId: DNS_ERROR_UNSECURE_PACKET
//
// MessageText:
//
// Unsecured DNS packet.
//
#define DNS_ERROR_UNSECURE_PACKET        9505L


#define DNS_ERROR_GENERAL_API_BASE 9550

// DNS_ERROR_INVALID_TYPE                0x0000254f
//
// MessageId: DNS_ERROR_INVALID_TYPE
//
// MessageText:
//
// Invalid DNS type.
//
#define DNS_ERROR_INVALID_TYPE           9551L

// DNS_ERROR_INVALID_IP_ADDRESS          0x00002550
//
// MessageId: DNS_ERROR_INVALID_IP_ADDRESS
//
// MessageText:
//
// Invalid IP address.
//
#define DNS_ERROR_INVALID_IP_ADDRESS     9552L

// DNS_ERROR_INVALID_PROPERTY            0x00002551
//
// MessageId: DNS_ERROR_INVALID_PROPERTY
//
// MessageText:
//
// Invalid property.
//
#define DNS_ERROR_INVALID_PROPERTY       9553L

// DNS_ERROR_TRY_AGAIN_LATER             0x00002552
//
// MessageId: DNS_ERROR_TRY_AGAIN_LATER
//
// MessageText:
//
// Try DNS operation again later.
//
#define DNS_ERROR_TRY_AGAIN_LATER        9554L

// DNS_ERROR_NOT_UNIQUE                  0x00002553
//
// MessageId: DNS_ERROR_NOT_UNIQUE
//
// MessageText:
//
// Record for given name and type is not unique.
//
#define DNS_ERROR_NOT_UNIQUE             9555L

// DNS_ERROR_NON_RFC_NAME                0x00002554
//
// MessageId: DNS_ERROR_NON_RFC_NAME
//
// MessageText:
//
// DNS name does not comply with RFC specifications.
//
#define DNS_ERROR_NON_RFC_NAME           9556L

// DNS_STATUS_FQDN                       0x00002555
//
// MessageId: DNS_STATUS_FQDN
//
// MessageText:
//
// DNS name is a fully-qualified DNS name.
//
#define DNS_STATUS_FQDN                  9557L

// DNS_STATUS_DOTTED_NAME                0x00002556
//
// MessageId: DNS_STATUS_DOTTED_NAME
//
// MessageText:
//
// DNS name is dotted (multi-label).
//
#define DNS_STATUS_DOTTED_NAME           9558L

// DNS_STATUS_SINGLE_PART_NAME           0x00002557
//
// MessageId: DNS_STATUS_SINGLE_PART_NAME
//
// MessageText:
//
// DNS name is a single-part name.
//
#define DNS_STATUS_SINGLE_PART_NAME      9559L

// DNS_ERROR_INVALID_NAME_CHAR           0x00002558
//
// MessageId: DNS_ERROR_INVALID_NAME_CHAR
//
// MessageText:
//
// DNS name contains an invalid character.
//
#define DNS_ERROR_INVALID_NAME_CHAR      9560L

// DNS_ERROR_NUMERIC_NAME                0x00002559
//
// MessageId: DNS_ERROR_NUMERIC_NAME
//
// MessageText:
//
// DNS name is entirely numeric.
//
#define DNS_ERROR_NUMERIC_NAME           9561L

// DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER  0x0000255A
//
// MessageId: DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER
//
// MessageText:
//
// The operation requested is not permitted on a DNS root server.
//
#define DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER 9562L

// DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION  0x0000255B
//
// MessageId: DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION
//
// MessageText:
//
// The record could not be created because this part of the DNS namespace has been delegated to another server.
//
#define DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION 9563L

// DNS_ERROR_CANNOT_FIND_ROOT_HINTS  0x0000255C
//
// MessageId: DNS_ERROR_CANNOT_FIND_ROOT_HINTS
//
// MessageText:
//
// The DNS server could not find a set of root hints.
//
#define DNS_ERROR_CANNOT_FIND_ROOT_HINTS 9564L

// DNS_ERROR_INCONSISTENT_ROOT_HINTS  0x0000255D
//
// MessageId: DNS_ERROR_INCONSISTENT_ROOT_HINTS
//
// MessageText:
//
// The DNS server found root hints but they were not consistent across all adapters.
//
#define DNS_ERROR_INCONSISTENT_ROOT_HINTS 9565L

// DNS_ERROR_DWORD_VALUE_TOO_SMALL    0x0000255E
//
// MessageId: DNS_ERROR_DWORD_VALUE_TOO_SMALL
//
// MessageText:
//
// The specified value is too small for this parameter.
//
#define DNS_ERROR_DWORD_VALUE_TOO_SMALL  9566L

// DNS_ERROR_DWORD_VALUE_TOO_LARGE    0x0000255F
//
// MessageId: DNS_ERROR_DWORD_VALUE_TOO_LARGE
//
// MessageText:
//
// The specified value is too large for this parameter.
//
#define DNS_ERROR_DWORD_VALUE_TOO_LARGE  9567L

// DNS_ERROR_BACKGROUND_LOADING       0x00002560
//
// MessageId: DNS_ERROR_BACKGROUND_LOADING
//
// MessageText:
//
// This operation is not allowed while the DNS server is loading zones in the background. Please try again later.
//
#define DNS_ERROR_BACKGROUND_LOADING     9568L

// DNS_ERROR_NOT_ALLOWED_ON_RODC      0x00002561
//
// MessageId: DNS_ERROR_NOT_ALLOWED_ON_RODC
//
// MessageText:
//
// The operation requested is not permitted on against a DNS server running on a read-only DC.
//
#define DNS_ERROR_NOT_ALLOWED_ON_RODC    9569L

// DNS_ERROR_NOT_ALLOWED_UNDER_DNAME   0x00002562
//
// MessageId: DNS_ERROR_NOT_ALLOWED_UNDER_DNAME
//
// MessageText:
//
// No data is allowed to exist underneath a DNAME record.
//
#define DNS_ERROR_NOT_ALLOWED_UNDER_DNAME 9570L


//
//  Zone errors
//

#define DNS_ERROR_ZONE_BASE 9600

// DNS_ERROR_ZONE_DOES_NOT_EXIST         0x00002581
//
// MessageId: DNS_ERROR_ZONE_DOES_NOT_EXIST
//
// MessageText:
//
// DNS zone does not exist.
//
#define DNS_ERROR_ZONE_DOES_NOT_EXIST    9601L

// DNS_ERROR_NO_ZONE_INFO                0x00002582
//
// MessageId: DNS_ERROR_NO_ZONE_INFO
//
// MessageText:
//
// DNS zone information not available.
//
#define DNS_ERROR_NO_ZONE_INFO           9602L

// DNS_ERROR_INVALID_ZONE_OPERATION      0x00002583
//
// MessageId: DNS_ERROR_INVALID_ZONE_OPERATION
//
// MessageText:
//
// Invalid operation for DNS zone.
//
#define DNS_ERROR_INVALID_ZONE_OPERATION 9603L

// DNS_ERROR_ZONE_CONFIGURATION_ERROR    0x00002584
//
// MessageId: DNS_ERROR_ZONE_CONFIGURATION_ERROR
//
// MessageText:
//
// Invalid DNS zone configuration.
//
#define DNS_ERROR_ZONE_CONFIGURATION_ERROR 9604L

// DNS_ERROR_ZONE_HAS_NO_SOA_RECORD      0x00002585
//
// MessageId: DNS_ERROR_ZONE_HAS_NO_SOA_RECORD
//
// MessageText:
//
// DNS zone has no start of authority (SOA) record.
//
#define DNS_ERROR_ZONE_HAS_NO_SOA_RECORD 9605L

// DNS_ERROR_ZONE_HAS_NO_NS_RECORDS      0x00002586
//
// MessageId: DNS_ERROR_ZONE_HAS_NO_NS_RECORDS
//
// MessageText:
//
// DNS zone has no Name Server (NS) record.
//
#define DNS_ERROR_ZONE_HAS_NO_NS_RECORDS 9606L

// DNS_ERROR_ZONE_LOCKED                 0x00002587
//
// MessageId: DNS_ERROR_ZONE_LOCKED
//
// MessageText:
//
// DNS zone is locked.
//
#define DNS_ERROR_ZONE_LOCKED            9607L

// DNS_ERROR_ZONE_CREATION_FAILED        0x00002588
//
// MessageId: DNS_ERROR_ZONE_CREATION_FAILED
//
// MessageText:
//
// DNS zone creation failed.
//
#define DNS_ERROR_ZONE_CREATION_FAILED   9608L

// DNS_ERROR_ZONE_ALREADY_EXISTS         0x00002589
//
// MessageId: DNS_ERROR_ZONE_ALREADY_EXISTS
//
// MessageText:
//
// DNS zone already exists.
//
#define DNS_ERROR_ZONE_ALREADY_EXISTS    9609L

// DNS_ERROR_AUTOZONE_ALREADY_EXISTS     0x0000258a
//
// MessageId: DNS_ERROR_AUTOZONE_ALREADY_EXISTS
//
// MessageText:
//
// DNS automatic zone already exists.
//
#define DNS_ERROR_AUTOZONE_ALREADY_EXISTS 9610L

// DNS_ERROR_INVALID_ZONE_TYPE           0x0000258b
//
// MessageId: DNS_ERROR_INVALID_ZONE_TYPE
//
// MessageText:
//
// Invalid DNS zone type.
//
#define DNS_ERROR_INVALID_ZONE_TYPE      9611L

// DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP 0x0000258c
//
// MessageId: DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP
//
// MessageText:
//
// Secondary DNS zone requires master IP address.
//
#define DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP 9612L

// DNS_ERROR_ZONE_NOT_SECONDARY          0x0000258d
//
// MessageId: DNS_ERROR_ZONE_NOT_SECONDARY
//
// MessageText:
//
// DNS zone not secondary.
//
#define DNS_ERROR_ZONE_NOT_SECONDARY     9613L

// DNS_ERROR_NEED_SECONDARY_ADDRESSES    0x0000258e
//
// MessageId: DNS_ERROR_NEED_SECONDARY_ADDRESSES
//
// MessageText:
//
// Need secondary IP address.
//
#define DNS_ERROR_NEED_SECONDARY_ADDRESSES 9614L

// DNS_ERROR_WINS_INIT_FAILED            0x0000258f
//
// MessageId: DNS_ERROR_WINS_INIT_FAILED
//
// MessageText:
//
// WINS initialization failed.
//
#define DNS_ERROR_WINS_INIT_FAILED       9615L

// DNS_ERROR_NEED_WINS_SERVERS           0x00002590
//
// MessageId: DNS_ERROR_NEED_WINS_SERVERS
//
// MessageText:
//
// Need WINS servers.
//
#define DNS_ERROR_NEED_WINS_SERVERS      9616L

// DNS_ERROR_NBSTAT_INIT_FAILED          0x00002591
//
// MessageId: DNS_ERROR_NBSTAT_INIT_FAILED
//
// MessageText:
//
// NBTSTAT initialization call failed.
//
#define DNS_ERROR_NBSTAT_INIT_FAILED     9617L

// DNS_ERROR_SOA_DELETE_INVALID          0x00002592
//
// MessageId: DNS_ERROR_SOA_DELETE_INVALID
//
// MessageText:
//
// Invalid delete of start of authority (SOA)
//
#define DNS_ERROR_SOA_DELETE_INVALID     9618L

// DNS_ERROR_FORWARDER_ALREADY_EXISTS    0x00002593
//
// MessageId: DNS_ERROR_FORWARDER_ALREADY_EXISTS
//
// MessageText:
//
// A conditional forwarding zone already exists for that name.
//
#define DNS_ERROR_FORWARDER_ALREADY_EXISTS 9619L

// DNS_ERROR_ZONE_REQUIRES_MASTER_IP     0x00002594
//
// MessageId: DNS_ERROR_ZONE_REQUIRES_MASTER_IP
//
// MessageText:
//
// This zone must be configured with one or more master DNS server IP addresses.
//
#define DNS_ERROR_ZONE_REQUIRES_MASTER_IP 9620L

// DNS_ERROR_ZONE_IS_SHUTDOWN            0x00002595
//
// MessageId: DNS_ERROR_ZONE_IS_SHUTDOWN
//
// MessageText:
//
// The operation cannot be performed because this zone is shutdown.
//
#define DNS_ERROR_ZONE_IS_SHUTDOWN       9621L


//
//  Datafile errors
//

#define DNS_ERROR_DATAFILE_BASE 9650

// DNS                                   0x000025b3
//
// MessageId: DNS_ERROR_PRIMARY_REQUIRES_DATAFILE
//
// MessageText:
//
// Primary DNS zone requires datafile.
//
#define DNS_ERROR_PRIMARY_REQUIRES_DATAFILE 9651L

// DNS                                   0x000025b4
//
// MessageId: DNS_ERROR_INVALID_DATAFILE_NAME
//
// MessageText:
//
// Invalid datafile name for DNS zone.
//
#define DNS_ERROR_INVALID_DATAFILE_NAME  9652L

// DNS                                   0x000025b5
//
// MessageId: DNS_ERROR_DATAFILE_OPEN_FAILURE
//
// MessageText:
//
// Failed to open datafile for DNS zone.
//
#define DNS_ERROR_DATAFILE_OPEN_FAILURE  9653L

// DNS                                   0x000025b6
//
// MessageId: DNS_ERROR_FILE_WRITEBACK_FAILED
//
// MessageText:
//
// Failed to write datafile for DNS zone.
//
#define DNS_ERROR_FILE_WRITEBACK_FAILED  9654L

// DNS                                   0x000025b7
//
// MessageId: DNS_ERROR_DATAFILE_PARSING
//
// MessageText:
//
// Failure while reading datafile for DNS zone.
//
#define DNS_ERROR_DATAFILE_PARSING       9655L


//
//  Database errors
//

#define DNS_ERROR_DATABASE_BASE 9700

// DNS_ERROR_RECORD_DOES_NOT_EXIST       0x000025e5
//
// MessageId: DNS_ERROR_RECORD_DOES_NOT_EXIST
//
// MessageText:
//
// DNS record does not exist.
//
#define DNS_ERROR_RECORD_DOES_NOT_EXIST  9701L

// DNS_ERROR_RECORD_FORMAT               0x000025e6
//
// MessageId: DNS_ERROR_RECORD_FORMAT
//
// MessageText:
//
// DNS record format error.
//
#define DNS_ERROR_RECORD_FORMAT          9702L

// DNS_ERROR_NODE_CREATION_FAILED        0x000025e7
//
// MessageId: DNS_ERROR_NODE_CREATION_FAILED
//
// MessageText:
//
// Node creation failure in DNS.
//
#define DNS_ERROR_NODE_CREATION_FAILED   9703L

// DNS_ERROR_UNKNOWN_RECORD_TYPE         0x000025e8
//
// MessageId: DNS_ERROR_UNKNOWN_RECORD_TYPE
//
// MessageText:
//
// Unknown DNS record type.
//
#define DNS_ERROR_UNKNOWN_RECORD_TYPE    9704L

// DNS_ERROR_RECORD_TIMED_OUT            0x000025e9
//
// MessageId: DNS_ERROR_RECORD_TIMED_OUT
//
// MessageText:
//
// DNS record timed out.
//
#define DNS_ERROR_RECORD_TIMED_OUT       9705L

// DNS_ERROR_NAME_NOT_IN_ZONE            0x000025ea
//
// MessageId: DNS_ERROR_NAME_NOT_IN_ZONE
//
// MessageText:
//
// Name not in DNS zone.
//
#define DNS_ERROR_NAME_NOT_IN_ZONE       9706L

// DNS_ERROR_CNAME_LOOP                  0x000025eb
//
// MessageId: DNS_ERROR_CNAME_LOOP
//
// MessageText:
//
// CNAME loop detected.
//
#define DNS_ERROR_CNAME_LOOP             9707L

// DNS_ERROR_NODE_IS_CNAME               0x000025ec
//
// MessageId: DNS_ERROR_NODE_IS_CNAME
//
// MessageText:
//
// Node is a CNAME DNS record.
//
#define DNS_ERROR_NODE_IS_CNAME          9708L

// DNS_ERROR_CNAME_COLLISION             0x000025ed
//
// MessageId: DNS_ERROR_CNAME_COLLISION
//
// MessageText:
//
// A CNAME record already exists for given name.
//
#define DNS_ERROR_CNAME_COLLISION        9709L

// DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT    0x000025ee
//
// MessageId: DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT
//
// MessageText:
//
// Record only at DNS zone root.
//
#define DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT 9710L

// DNS_ERROR_RECORD_ALREADY_EXISTS       0x000025ef
//
// MessageId: DNS_ERROR_RECORD_ALREADY_EXISTS
//
// MessageText:
//
// DNS record already exists.
//
#define DNS_ERROR_RECORD_ALREADY_EXISTS  9711L

// DNS_ERROR_SECONDARY_DATA              0x000025f0
//
// MessageId: DNS_ERROR_SECONDARY_DATA
//
// MessageText:
//
// Secondary DNS zone data error.
//
#define DNS_ERROR_SECONDARY_DATA         9712L

// DNS_ERROR_NO_CREATE_CACHE_DATA        0x000025f1
//
// MessageId: DNS_ERROR_NO_CREATE_CACHE_DATA
//
// MessageText:
//
// Could not create DNS cache data.
//
#define DNS_ERROR_NO_CREATE_CACHE_DATA   9713L

// DNS_ERROR_NAME_DOES_NOT_EXIST         0x000025f2
//
// MessageId: DNS_ERROR_NAME_DOES_NOT_EXIST
//
// MessageText:
//
// DNS name does not exist.
//
#define DNS_ERROR_NAME_DOES_NOT_EXIST    9714L

// DNS_WARNING_PTR_CREATE_FAILED         0x000025f3
//
// MessageId: DNS_WARNING_PTR_CREATE_FAILED
//
// MessageText:
//
// Could not create pointer (PTR) record.
//
#define DNS_WARNING_PTR_CREATE_FAILED    9715L

// DNS_WARNING_DOMAIN_UNDELETED          0x000025f4
//
// MessageId: DNS_WARNING_DOMAIN_UNDELETED
//
// MessageText:
//
// DNS domain was undeleted.
//
#define DNS_WARNING_DOMAIN_UNDELETED     9716L

// DNS_ERROR_DS_UNAVAILABLE              0x000025f5
//
// MessageId: DNS_ERROR_DS_UNAVAILABLE
//
// MessageText:
//
// The directory service is unavailable.
//
#define DNS_ERROR_DS_UNAVAILABLE         9717L

// DNS_ERROR_DS_ZONE_ALREADY_EXISTS      0x000025f6
//
// MessageId: DNS_ERROR_DS_ZONE_ALREADY_EXISTS
//
// MessageText:
//
// DNS zone already exists in the directory service.
//
#define DNS_ERROR_DS_ZONE_ALREADY_EXISTS 9718L

// DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE      0x000025f7
//
// MessageId: DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE
//
// MessageText:
//
// DNS server not creating or reading the boot file for the directory service integrated DNS zone.
//
#define DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE 9719L

// DNS_ERROR_NODE_IS_DNAME               0x000025f8
//
// MessageId: DNS_ERROR_NODE_IS_DNAME
//
// MessageText:
//
// Node is a DNAME DNS record.
//
#define DNS_ERROR_NODE_IS_DNAME          9720L

// DNS_ERROR_DNAME_COLLISION             0x000025f9
//
// MessageId: DNS_ERROR_DNAME_COLLISION
//
// MessageText:
//
// A DNAME record already exists for given name.
//
#define DNS_ERROR_DNAME_COLLISION        9721L

// DNS_ERROR_ALIAS_LOOP                  0x000025fa
//
// MessageId: DNS_ERROR_ALIAS_LOOP
//
// MessageText:
//
// An alias loop has been detected with either CNAME or DNAME records.
//
#define DNS_ERROR_ALIAS_LOOP             9722L


//
//  Operation errors
//

#define DNS_ERROR_OPERATION_BASE 9750

// DNS_INFO_AXFR_COMPLETE                0x00002617
//
// MessageId: DNS_INFO_AXFR_COMPLETE
//
// MessageText:
//
// DNS AXFR (zone transfer) complete.
//
#define DNS_INFO_AXFR_COMPLETE           9751L

// DNS_ERROR_AXFR                        0x00002618
//
// MessageId: DNS_ERROR_AXFR
//
// MessageText:
//
// DNS zone transfer failed.
//
#define DNS_ERROR_AXFR                   9752L

// DNS_INFO_ADDED_LOCAL_WINS             0x00002619
//
// MessageId: DNS_INFO_ADDED_LOCAL_WINS
//
// MessageText:
//
// Added local WINS server.
//
#define DNS_INFO_ADDED_LOCAL_WINS        9753L


//
//  Secure update
//

#define DNS_ERROR_SECURE_BASE 9800

// DNS_STATUS_CONTINUE_NEEDED            0x00002649
//
// MessageId: DNS_STATUS_CONTINUE_NEEDED
//
// MessageText:
//
// Secure update call needs to continue update request.
//
#define DNS_STATUS_CONTINUE_NEEDED       9801L


//
//  Setup errors
//

#define DNS_ERROR_SETUP_BASE 9850

// DNS_ERROR_NO_TCPIP                    0x0000267b
//
// MessageId: DNS_ERROR_NO_TCPIP
//
// MessageText:
//
// TCP/IP network protocol not installed.
//
#define DNS_ERROR_NO_TCPIP               9851L

// DNS_ERROR_NO_DNS_SERVERS              0x0000267c
//
// MessageId: DNS_ERROR_NO_DNS_SERVERS
//
// MessageText:
//
// No DNS servers configured for local system.
//
#define DNS_ERROR_NO_DNS_SERVERS         9852L


//
//  Directory partition (DP) errors
//

#define DNS_ERROR_DP_BASE 9900

// DNS_ERROR_DP_DOES_NOT_EXIST           0x000026ad
//
// MessageId: DNS_ERROR_DP_DOES_NOT_EXIST
//
// MessageText:
//
// The specified directory partition does not exist.
//
#define DNS_ERROR_DP_DOES_NOT_EXIST      9901L

// DNS_ERROR_DP_ALREADY_EXISTS           0x000026ae
//
// MessageId: DNS_ERROR_DP_ALREADY_EXISTS
//
// MessageText:
//
// The specified directory partition already exists.
//
#define DNS_ERROR_DP_ALREADY_EXISTS      9902L

// DNS_ERROR_DP_NOT_ENLISTED             0x000026af
//
// MessageId: DNS_ERROR_DP_NOT_ENLISTED
//
// MessageText:
//
// This DNS server is not enlisted in the specified directory partition.
//
#define DNS_ERROR_DP_NOT_ENLISTED        9903L

// DNS_ERROR_DP_ALREADY_ENLISTED         0x000026b0
//
// MessageId: DNS_ERROR_DP_ALREADY_ENLISTED
//
// MessageText:
//
// This DNS server is already enlisted in the specified directory partition.
//
#define DNS_ERROR_DP_ALREADY_ENLISTED    9904L

// DNS_ERROR_DP_NOT_AVAILABLE            0x000026b1
//
// MessageId: DNS_ERROR_DP_NOT_AVAILABLE
//
// MessageText:
//
// The directory partition is not available at this time. Please wait a few minutes and try again.
//
#define DNS_ERROR_DP_NOT_AVAILABLE       9905L

// DNS_ERROR_DP_FSMO_ERROR               0x000026b2
//
// MessageId: DNS_ERROR_DP_FSMO_ERROR
//
// MessageText:
//
// The application directory partition operation failed. The domain controller holding the domain naming master role is down or unable to service the request or is not running Windows Server 2003.
//
#define DNS_ERROR_DP_FSMO_ERROR          9906L


///////////////////////////////////////////////////
//                                               //
//             End of DNS Error Codes            //
//                                               //
//                  9000 to 9999                 //
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//                                               //
//               WinSock Error Codes             //
//                                               //
//                 10000 to 11999                //
///////////////////////////////////////////////////

//
// WinSock error codes are also defined in WinSock.h
// and WinSock2.h, hence the IFDEF
//
#define WSABASEERR 10000
//
// MessageId: WSAEINTR
//
// MessageText:
//
// A blocking operation was interrupted by a call to WSACancelBlockingCall.
//
#define WSAEINTR                         10004L

//
// MessageId: WSAEBADF
//
// MessageText:
//
// The file handle supplied is not valid.
//
#define WSAEBADF                         10009L

//
// MessageId: WSAEACCES
//
// MessageText:
//
// An attempt was made to access a socket in a way forbidden by its access permissions.
//
#define WSAEACCES                        10013L

//
// MessageId: WSAEFAULT
//
// MessageText:
//
// The system detected an invalid pointer address in attempting to use a pointer argument in a call.
//
#define WSAEFAULT                        10014L

//
// MessageId: WSAEINVAL
//
// MessageText:
//
// An invalid argument was supplied.
//
#define WSAEINVAL                        10022L

//
// MessageId: WSAEMFILE
//
// MessageText:
//
// Too many open sockets.
//
#define WSAEMFILE                        10024L

//
// MessageId: WSAEWOULDBLOCK
//
// MessageText:
//
// A non-blocking socket operation could not be completed immediately.
//
#define WSAEWOULDBLOCK                   10035L

//
// MessageId: WSAEINPROGRESS
//
// MessageText:
//
// A blocking operation is currently executing.
//
#define WSAEINPROGRESS                   10036L

//
// MessageId: WSAEALREADY
//
// MessageText:
//
// An operation was attempted on a non-blocking socket that already had an operation in progress.
//
#define WSAEALREADY                      10037L

//
// MessageId: WSAENOTSOCK
//
// MessageText:
//
// An operation was attempted on something that is not a socket.
//
#define WSAENOTSOCK                      10038L

//
// MessageId: WSAEDESTADDRREQ
//
// MessageText:
//
// A required address was omitted from an operation on a socket.
//
#define WSAEDESTADDRREQ                  10039L

//
// MessageId: WSAEMSGSIZE
//
// MessageText:
//
// A message sent on a datagram socket was larger than the internal message buffer or some other network limit, or the buffer used to receive a datagram into was smaller than the datagram itself.
//
#define WSAEMSGSIZE                      10040L

//
// MessageId: WSAEPROTOTYPE
//
// MessageText:
//
// A protocol was specified in the socket function call that does not support the semantics of the socket type requested.
//
#define WSAEPROTOTYPE                    10041L

//
// MessageId: WSAENOPROTOOPT
//
// MessageText:
//
// An unknown, invalid, or unsupported option or level was specified in a getsockopt or setsockopt call.
//
#define WSAENOPROTOOPT                   10042L

//
// MessageId: WSAEPROTONOSUPPORT
//
// MessageText:
//
// The requested protocol has not been configured into the system, or no implementation for it exists.
//
#define WSAEPROTONOSUPPORT               10043L

//
// MessageId: WSAESOCKTNOSUPPORT
//
// MessageText:
//
// The support for the specified socket type does not exist in this address family.
//
#define WSAESOCKTNOSUPPORT               10044L

//
// MessageId: WSAEOPNOTSUPP
//
// MessageText:
//
// The attempted operation is not supported for the type of object referenced.
//
#define WSAEOPNOTSUPP                    10045L

//
// MessageId: WSAEPFNOSUPPORT
//
// MessageText:
//
// The protocol family has not been configured into the system or no implementation for it exists.
//
#define WSAEPFNOSUPPORT                  10046L

//
// MessageId: WSAEAFNOSUPPORT
//
// MessageText:
//
// An address incompatible with the requested protocol was used.
//
#define WSAEAFNOSUPPORT                  10047L

//
// MessageId: WSAEADDRINUSE
//
// MessageText:
//
// Only one usage of each socket address (protocol/network address/port) is normally permitted.
//
#define WSAEADDRINUSE                    10048L

//
// MessageId: WSAEADDRNOTAVAIL
//
// MessageText:
//
// The requested address is not valid in its context.
//
#define WSAEADDRNOTAVAIL                 10049L

//
// MessageId: WSAENETDOWN
//
// MessageText:
//
// A socket operation encountered a dead network.
//
#define WSAENETDOWN                      10050L

//
// MessageId: WSAENETUNREACH
//
// MessageText:
//
// A socket operation was attempted to an unreachable network.
//
#define WSAENETUNREACH                   10051L

//
// MessageId: WSAENETRESET
//
// MessageText:
//
// The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress.
//
#define WSAENETRESET                     10052L

//
// MessageId: WSAECONNABORTED
//
// MessageText:
//
// An established connection was aborted by the software in your host machine.
//
#define WSAECONNABORTED                  10053L

//
// MessageId: WSAECONNRESET
//
// MessageText:
//
// An existing connection was forcibly closed by the remote host.
//
#define WSAECONNRESET                    10054L

//
// MessageId: WSAENOBUFS
//
// MessageText:
//
// An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full.
//
#define WSAENOBUFS                       10055L

//
// MessageId: WSAEISCONN
//
// MessageText:
//
// A connect request was made on an already connected socket.
//
#define WSAEISCONN                       10056L

//
// MessageId: WSAENOTCONN
//
// MessageText:
//
// A request to send or receive data was disallowed because the socket is not connected and (when sending on a datagram socket using a sendto call) no address was supplied.
//
#define WSAENOTCONN                      10057L

//
// MessageId: WSAESHUTDOWN
//
// MessageText:
//
// A request to send or receive data was disallowed because the socket had already been shut down in that direction with a previous shutdown call.
//
#define WSAESHUTDOWN                     10058L

//
// MessageId: WSAETOOMANYREFS
//
// MessageText:
//
// Too many references to some kernel object.
//
#define WSAETOOMANYREFS                  10059L

//
// MessageId: WSAETIMEDOUT
//
// MessageText:
//
// A connection attempt failed because the connected party did not properly respond after a period of time, or established connection failed because connected host has failed to respond.
//
#define WSAETIMEDOUT                     10060L

//
// MessageId: WSAECONNREFUSED
//
// MessageText:
//
// No connection could be made because the target machine actively refused it.
//
#define WSAECONNREFUSED                  10061L

//
// MessageId: WSAELOOP
//
// MessageText:
//
// Cannot translate name.
//
#define WSAELOOP                         10062L

//
// MessageId: WSAENAMETOOLONG
//
// MessageText:
//
// Name component or name was too long.
//
#define WSAENAMETOOLONG                  10063L

//
// MessageId: WSAEHOSTDOWN
//
// MessageText:
//
// A socket operation failed because the destination host was down.
//
#define WSAEHOSTDOWN                     10064L

//
// MessageId: WSAEHOSTUNREACH
//
// MessageText:
//
// A socket operation was attempted to an unreachable host.
//
#define WSAEHOSTUNREACH                  10065L

//
// MessageId: WSAENOTEMPTY
//
// MessageText:
//
// Cannot remove a directory that is not empty.
//
#define WSAENOTEMPTY                     10066L

//
// MessageId: WSAEPROCLIM
//
// MessageText:
//
// A Windows Sockets implementation may have a limit on the number of applications that may use it simultaneously.
//
#define WSAEPROCLIM                      10067L

//
// MessageId: WSAEUSERS
//
// MessageText:
//
// Ran out of quota.
//
#define WSAEUSERS                        10068L

//
// MessageId: WSAEDQUOT
//
// MessageText:
//
// Ran out of disk quota.
//
#define WSAEDQUOT                        10069L

//
// MessageId: WSAESTALE
//
// MessageText:
//
// File handle reference is no longer available.
//
#define WSAESTALE                        10070L

//
// MessageId: WSAEREMOTE
//
// MessageText:
//
// Item is not available locally.
//
#define WSAEREMOTE                       10071L

//
// MessageId: WSASYSNOTREADY
//
// MessageText:
//
// WSAStartup cannot function at this time because the underlying system it uses to provide network services is currently unavailable.
//
#define WSASYSNOTREADY                   10091L

//
// MessageId: WSAVERNOTSUPPORTED
//
// MessageText:
//
// The Windows Sockets version requested is not supported.
//
#define WSAVERNOTSUPPORTED               10092L

//
// MessageId: WSANOTINITIALISED
//
// MessageText:
//
// Either the application has not called WSAStartup, or WSAStartup failed.
//
#define WSANOTINITIALISED                10093L

//
// MessageId: WSAEDISCON
//
// MessageText:
//
// Returned by WSARecv or WSARecvFrom to indicate the remote party has initiated a graceful shutdown sequence.
//
#define WSAEDISCON                       10101L

//
// MessageId: WSAENOMORE
//
// MessageText:
//
// No more results can be returned by WSALookupServiceNext.
//
#define WSAENOMORE                       10102L

//
// MessageId: WSAECANCELLED
//
// MessageText:
//
// A call to WSALookupServiceEnd was made while this call was still processing. The call has been canceled.
//
#define WSAECANCELLED                    10103L

//
// MessageId: WSAEINVALIDPROCTABLE
//
// MessageText:
//
// The procedure call table is invalid.
//
#define WSAEINVALIDPROCTABLE             10104L

//
// MessageId: WSAEINVALIDPROVIDER
//
// MessageText:
//
// The requested service provider is invalid.
//
#define WSAEINVALIDPROVIDER              10105L

//
// MessageId: WSAEPROVIDERFAILEDINIT
//
// MessageText:
//
// The requested service provider could not be loaded or initialized.
//
#define WSAEPROVIDERFAILEDINIT           10106L

//
// MessageId: WSASYSCALLFAILURE
//
// MessageText:
//
// A system call that should never fail has failed.
//
#define WSASYSCALLFAILURE                10107L

//
// MessageId: WSASERVICE_NOT_FOUND
//
// MessageText:
//
// No such service is known. The service cannot be found in the specified name space.
//
#define WSASERVICE_NOT_FOUND             10108L

//
// MessageId: WSATYPE_NOT_FOUND
//
// MessageText:
//
// The specified class was not found.
//
#define WSATYPE_NOT_FOUND                10109L

//
// MessageId: WSA_E_NO_MORE
//
// MessageText:
//
// No more results can be returned by WSALookupServiceNext.
//
#define WSA_E_NO_MORE                    10110L

//
// MessageId: WSA_E_CANCELLED
//
// MessageText:
//
// A call to WSALookupServiceEnd was made while this call was still processing. The call has been canceled.
//
#define WSA_E_CANCELLED                  10111L

//
// MessageId: WSAEREFUSED
//
// MessageText:
//
// A database query failed because it was actively refused.
//
#define WSAEREFUSED                      10112L

//
// MessageId: WSAHOST_NOT_FOUND
//
// MessageText:
//
// No such host is known.
//
#define WSAHOST_NOT_FOUND                11001L

//
// MessageId: WSATRY_AGAIN
//
// MessageText:
//
// This is usually a temporary error during hostname resolution and means that the local server did not receive a response from an authoritative server.
//
#define WSATRY_AGAIN                     11002L

//
// MessageId: WSANO_RECOVERY
//
// MessageText:
//
// A non-recoverable error occurred during a database lookup.
//
#define WSANO_RECOVERY                   11003L

//
// MessageId: WSANO_DATA
//
// MessageText:
//
// The requested name is valid, but no data of the requested type was found.
//
#define WSANO_DATA                       11004L

//
// MessageId: WSA_QOS_RECEIVERS
//
// MessageText:
//
// At least one reserve has arrived.
//
#define WSA_QOS_RECEIVERS                11005L

//
// MessageId: WSA_QOS_SENDERS
//
// MessageText:
//
// At least one path has arrived.
//
#define WSA_QOS_SENDERS                  11006L

//
// MessageId: WSA_QOS_NO_SENDERS
//
// MessageText:
//
// There are no senders.
//
#define WSA_QOS_NO_SENDERS               11007L

//
// MessageId: WSA_QOS_NO_RECEIVERS
//
// MessageText:
//
// There are no receivers.
//
#define WSA_QOS_NO_RECEIVERS             11008L

//
// MessageId: WSA_QOS_REQUEST_CONFIRMED
//
// MessageText:
//
// Reserve has been confirmed.
//
#define WSA_QOS_REQUEST_CONFIRMED        11009L

//
// MessageId: WSA_QOS_ADMISSION_FAILURE
//
// MessageText:
//
// Error due to lack of resources.
//
#define WSA_QOS_ADMISSION_FAILURE        11010L

//
// MessageId: WSA_QOS_POLICY_FAILURE
//
// MessageText:
//
// Rejected for administrative reasons - bad credentials.
//
#define WSA_QOS_POLICY_FAILURE           11011L

//
// MessageId: WSA_QOS_BAD_STYLE
//
// MessageText:
//
// Unknown or conflicting style.
//
#define WSA_QOS_BAD_STYLE                11012L

//
// MessageId: WSA_QOS_BAD_OBJECT
//
// MessageText:
//
// Problem with some part of the filterspec or providerspecific buffer in general.
//
#define WSA_QOS_BAD_OBJECT               11013L

//
// MessageId: WSA_QOS_TRAFFIC_CTRL_ERROR
//
// MessageText:
//
// Problem with some part of the flowspec.
//
#define WSA_QOS_TRAFFIC_CTRL_ERROR       11014L

//
// MessageId: WSA_QOS_GENERIC_ERROR
//
// MessageText:
//
// General QOS error.
//
#define WSA_QOS_GENERIC_ERROR            11015L

//
// MessageId: WSA_QOS_ESERVICETYPE
//
// MessageText:
//
// An invalid or unrecognized service type was found in the flowspec.
//
#define WSA_QOS_ESERVICETYPE             11016L

//
// MessageId: WSA_QOS_EFLOWSPEC
//
// MessageText:
//
// An invalid or inconsistent flowspec was found in the QOS structure.
//
#define WSA_QOS_EFLOWSPEC                11017L

//
// MessageId: WSA_QOS_EPROVSPECBUF
//
// MessageText:
//
// Invalid QOS provider-specific buffer.
//
#define WSA_QOS_EPROVSPECBUF             11018L

//
// MessageId: WSA_QOS_EFILTERSTYLE
//
// MessageText:
//
// An invalid QOS filter style was used.
//
#define WSA_QOS_EFILTERSTYLE             11019L

//
// MessageId: WSA_QOS_EFILTERTYPE
//
// MessageText:
//
// An invalid QOS filter type was used.
//
#define WSA_QOS_EFILTERTYPE              11020L

//
// MessageId: WSA_QOS_EFILTERCOUNT
//
// MessageText:
//
// An incorrect number of QOS FILTERSPECs were specified in the FLOWDESCRIPTOR.
//
#define WSA_QOS_EFILTERCOUNT             11021L

//
// MessageId: WSA_QOS_EOBJLENGTH
//
// MessageText:
//
// An object with an invalid ObjectLength field was specified in the QOS provider-specific buffer.
//
#define WSA_QOS_EOBJLENGTH               11022L

//
// MessageId: WSA_QOS_EFLOWCOUNT
//
// MessageText:
//
// An incorrect number of flow descriptors was specified in the QOS structure.
//
#define WSA_QOS_EFLOWCOUNT               11023L

//
// MessageId: WSA_QOS_EUNKOWNPSOBJ
//
// MessageText:
//
// An unrecognized object was found in the QOS provider-specific buffer.
//
#define WSA_QOS_EUNKOWNPSOBJ             11024L

//
// MessageId: WSA_QOS_EPOLICYOBJ
//
// MessageText:
//
// An invalid policy object was found in the QOS provider-specific buffer.
//
#define WSA_QOS_EPOLICYOBJ               11025L

//
// MessageId: WSA_QOS_EFLOWDESC
//
// MessageText:
//
// An invalid QOS flow descriptor was found in the flow descriptor list.
//
#define WSA_QOS_EFLOWDESC                11026L

//
// MessageId: WSA_QOS_EPSFLOWSPEC
//
// MessageText:
//
// An invalid or inconsistent flowspec was found in the QOS provider specific buffer.
//
#define WSA_QOS_EPSFLOWSPEC              11027L

//
// MessageId: WSA_QOS_EPSFILTERSPEC
//
// MessageText:
//
// An invalid FILTERSPEC was found in the QOS provider-specific buffer.
//
#define WSA_QOS_EPSFILTERSPEC            11028L

//
// MessageId: WSA_QOS_ESDMODEOBJ
//
// MessageText:
//
// An invalid shape discard mode object was found in the QOS provider specific buffer.
//
#define WSA_QOS_ESDMODEOBJ               11029L

//
// MessageId: WSA_QOS_ESHAPERATEOBJ
//
// MessageText:
//
// An invalid shaping rate object was found in the QOS provider-specific buffer.
//
#define WSA_QOS_ESHAPERATEOBJ            11030L

//
// MessageId: WSA_QOS_RESERVED_PETYPE
//
// MessageText:
//
// A reserved policy element was found in the QOS provider-specific buffer.
//
#define WSA_QOS_RESERVED_PETYPE          11031L

#endif // defined(WSABASEERR)

///////////////////////////////////////////////////
//                                               //
//           End of WinSock Error Codes          //
//                                               //
//                 10000 to 11999                //
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//                                               //
//                  Available                    //
//                                               //
//                12000 to 129999                //
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//                                               //
//           Start of IPSec Error codes          //
//                                               //
//                 13000 to 13999                //
///////////////////////////////////////////////////

//
// MessageId: ERROR_IPSEC_QM_POLICY_EXISTS
//
// MessageText:
//
// The specified quick mode policy already exists.
//
#define ERROR_IPSEC_QM_POLICY_EXISTS     13000L

//
// MessageId: ERROR_IPSEC_QM_POLICY_NOT_FOUND
//
// MessageText:
//
// The specified quick mode policy was not found.
//
#define ERROR_IPSEC_QM_POLICY_NOT_FOUND  13001L

//
// MessageId: ERROR_IPSEC_QM_POLICY_IN_USE
//
// MessageText:
//
// The specified quick mode policy is being used.
//
#define ERROR_IPSEC_QM_POLICY_IN_USE     13002L

//
// MessageId: ERROR_IPSEC_MM_POLICY_EXISTS
//
// MessageText:
//
// The specified main mode policy already exists.
//
#define ERROR_IPSEC_MM_POLICY_EXISTS     13003L

//
// MessageId: ERROR_IPSEC_MM_POLICY_NOT_FOUND
//
// MessageText:
//
// The specified main mode policy was not found
//
#define ERROR_IPSEC_MM_POLICY_NOT_FOUND  13004L

//
// MessageId: ERROR_IPSEC_MM_POLICY_IN_USE
//
// MessageText:
//
// The specified main mode policy is being used.
//
#define ERROR_IPSEC_MM_POLICY_IN_USE     13005L

//
// MessageId: ERROR_IPSEC_MM_FILTER_EXISTS
//
// MessageText:
//
// The specified main mode filter already exists.
//
#define ERROR_IPSEC_MM_FILTER_EXISTS     13006L

//
// MessageId: ERROR_IPSEC_MM_FILTER_NOT_FOUND
//
// MessageText:
//
// The specified main mode filter was not found.
//
#define ERROR_IPSEC_MM_FILTER_NOT_FOUND  13007L

//
// MessageId: ERROR_IPSEC_TRANSPORT_FILTER_EXISTS
//
// MessageText:
//
// The specified transport mode filter already exists.
//
#define ERROR_IPSEC_TRANSPORT_FILTER_EXISTS 13008L

//
// MessageId: ERROR_IPSEC_TRANSPORT_FILTER_NOT_FOUND
//
// MessageText:
//
// The specified transport mode filter does not exist.
//
#define ERROR_IPSEC_TRANSPORT_FILTER_NOT_FOUND 13009L

//
// MessageId: ERROR_IPSEC_MM_AUTH_EXISTS
//
// MessageText:
//
// The specified main mode authentication list exists.
//
#define ERROR_IPSEC_MM_AUTH_EXISTS       13010L

//
// MessageId: ERROR_IPSEC_MM_AUTH_NOT_FOUND
//
// MessageText:
//
// The specified main mode authentication list was not found.
//
#define ERROR_IPSEC_MM_AUTH_NOT_FOUND    13011L

//
// MessageId: ERROR_IPSEC_MM_AUTH_IN_USE
//
// MessageText:
//
// The specified main mode authentication list is being used.
//
#define ERROR_IPSEC_MM_AUTH_IN_USE       13012L

//
// MessageId: ERROR_IPSEC_DEFAULT_MM_POLICY_NOT_FOUND
//
// MessageText:
//
// The specified default main mode policy was not found.
//
#define ERROR_IPSEC_DEFAULT_MM_POLICY_NOT_FOUND 13013L

//
// MessageId: ERROR_IPSEC_DEFAULT_MM_AUTH_NOT_FOUND
//
// MessageText:
//
// The specified default main mode authentication list was not found.
//
#define ERROR_IPSEC_DEFAULT_MM_AUTH_NOT_FOUND 13014L

//
// MessageId: ERROR_IPSEC_DEFAULT_QM_POLICY_NOT_FOUND
//
// MessageText:
//
// The specified default quick mode policy was not found.
//
#define ERROR_IPSEC_DEFAULT_QM_POLICY_NOT_FOUND 13015L

//
// MessageId: ERROR_IPSEC_TUNNEL_FILTER_EXISTS
//
// MessageText:
//
// The specified tunnel mode filter exists.
//
#define ERROR_IPSEC_TUNNEL_FILTER_EXISTS 13016L

//
// MessageId: ERROR_IPSEC_TUNNEL_FILTER_NOT_FOUND
//
// MessageText:
//
// The specified tunnel mode filter was not found.
//
#define ERROR_IPSEC_TUNNEL_FILTER_NOT_FOUND 13017L

//
// MessageId: ERROR_IPSEC_MM_FILTER_PENDING_DELETION
//
// MessageText:
//
// The Main Mode filter is pending deletion.
//
#define ERROR_IPSEC_MM_FILTER_PENDING_DELETION 13018L

//
// MessageId: ERROR_IPSEC_TRANSPORT_FILTER_PENDING_DELETION
//
// MessageText:
//
// The transport filter is pending deletion.
//
#define ERROR_IPSEC_TRANSPORT_FILTER_PENDING_DELETION 13019L

//
// MessageId: ERROR_IPSEC_TUNNEL_FILTER_PENDING_DELETION
//
// MessageText:
//
// The tunnel filter is pending deletion.
//
#define ERROR_IPSEC_TUNNEL_FILTER_PENDING_DELETION 13020L

//
// MessageId: ERROR_IPSEC_MM_POLICY_PENDING_DELETION
//
// MessageText:
//
// The Main Mode policy is pending deletion.
//
#define ERROR_IPSEC_MM_POLICY_PENDING_DELETION 13021L

//
// MessageId: ERROR_IPSEC_MM_AUTH_PENDING_DELETION
//
// MessageText:
//
// The Main Mode authentication bundle is pending deletion.
//
#define ERROR_IPSEC_MM_AUTH_PENDING_DELETION 13022L

//
// MessageId: ERROR_IPSEC_QM_POLICY_PENDING_DELETION
//
// MessageText:
//
// The Quick Mode policy is pending deletion.
//
#define ERROR_IPSEC_QM_POLICY_PENDING_DELETION 13023L

//
// MessageId: WARNING_IPSEC_MM_POLICY_PRUNED
//
// MessageText:
//
// The Main Mode policy was successfully added, but some of the requested offers are not supported.
//
#define WARNING_IPSEC_MM_POLICY_PRUNED   13024L

//
// MessageId: WARNING_IPSEC_QM_POLICY_PRUNED
//
// MessageText:
//
// The Quick Mode policy was successfully added, but some of the requested offers are not supported.
//
#define WARNING_IPSEC_QM_POLICY_PRUNED   13025L

//
// MessageId: ERROR_IPSEC_IKE_NEG_STATUS_BEGIN
//
// MessageText:
//
//  ERROR_IPSEC_IKE_NEG_STATUS_BEGIN
//
#define ERROR_IPSEC_IKE_NEG_STATUS_BEGIN 13800L

//
// MessageId: ERROR_IPSEC_IKE_AUTH_FAIL
//
// MessageText:
//
// IKE authentication credentials are unacceptable
//
#define ERROR_IPSEC_IKE_AUTH_FAIL        13801L

//
// MessageId: ERROR_IPSEC_IKE_ATTRIB_FAIL
//
// MessageText:
//
// IKE security attributes are unacceptable
//
#define ERROR_IPSEC_IKE_ATTRIB_FAIL      13802L

//
// MessageId: ERROR_IPSEC_IKE_NEGOTIATION_PENDING
//
// MessageText:
//
// IKE Negotiation in progress
//
#define ERROR_IPSEC_IKE_NEGOTIATION_PENDING 13803L

//
// MessageId: ERROR_IPSEC_IKE_GENERAL_PROCESSING_ERROR
//
// MessageText:
//
// General processing error
//
#define ERROR_IPSEC_IKE_GENERAL_PROCESSING_ERROR 13804L

//
// MessageId: ERROR_IPSEC_IKE_TIMED_OUT
//
// MessageText:
//
// Negotiation timed out
//
#define ERROR_IPSEC_IKE_TIMED_OUT        13805L

//
// MessageId: ERROR_IPSEC_IKE_NO_CERT
//
// MessageText:
//
// IKE failed to find valid machine certificate. Contact your Network Security Administrator about installing a valid certificate in the appropriate Certificate Store.
//
#define ERROR_IPSEC_IKE_NO_CERT          13806L

//
// MessageId: ERROR_IPSEC_IKE_SA_DELETED
//
// MessageText:
//
// IKE SA deleted by peer before establishment completed
//
#define ERROR_IPSEC_IKE_SA_DELETED       13807L

//
// MessageId: ERROR_IPSEC_IKE_SA_REAPED
//
// MessageText:
//
// IKE SA deleted before establishment completed
//
#define ERROR_IPSEC_IKE_SA_REAPED        13808L

//
// MessageId: ERROR_IPSEC_IKE_MM_ACQUIRE_DROP
//
// MessageText:
//
// Negotiation request sat in Queue too long
//
#define ERROR_IPSEC_IKE_MM_ACQUIRE_DROP  13809L

//
// MessageId: ERROR_IPSEC_IKE_QM_ACQUIRE_DROP
//
// MessageText:
//
// Negotiation request sat in Queue too long
//
#define ERROR_IPSEC_IKE_QM_ACQUIRE_DROP  13810L

//
// MessageId: ERROR_IPSEC_IKE_QUEUE_DROP_MM
//
// MessageText:
//
// Negotiation request sat in Queue too long
//
#define ERROR_IPSEC_IKE_QUEUE_DROP_MM    13811L

//
// MessageId: ERROR_IPSEC_IKE_QUEUE_DROP_NO_MM
//
// MessageText:
//
// Negotiation request sat in Queue too long
//
#define ERROR_IPSEC_IKE_QUEUE_DROP_NO_MM 13812L

//
// MessageId: ERROR_IPSEC_IKE_DROP_NO_RESPONSE
//
// MessageText:
//
// No response from peer
//
#define ERROR_IPSEC_IKE_DROP_NO_RESPONSE 13813L

//
// MessageId: ERROR_IPSEC_IKE_MM_DELAY_DROP
//
// MessageText:
//
// Negotiation took too long
//
#define ERROR_IPSEC_IKE_MM_DELAY_DROP    13814L

//
// MessageId: ERROR_IPSEC_IKE_QM_DELAY_DROP
//
// MessageText:
//
// Negotiation took too long
//
#define ERROR_IPSEC_IKE_QM_DELAY_DROP    13815L

//
// MessageId: ERROR_IPSEC_IKE_ERROR
//
// MessageText:
//
// Unknown error occurred
//
#define ERROR_IPSEC_IKE_ERROR            13816L

//
// MessageId: ERROR_IPSEC_IKE_CRL_FAILED
//
// MessageText:
//
// Certificate Revocation Check failed
//
#define ERROR_IPSEC_IKE_CRL_FAILED       13817L

//
// MessageId: ERROR_IPSEC_IKE_INVALID_KEY_USAGE
//
// MessageText:
//
// Invalid certificate key usage
//
#define ERROR_IPSEC_IKE_INVALID_KEY_USAGE 13818L

//
// MessageId: ERROR_IPSEC_IKE_INVALID_CERT_TYPE
//
// MessageText:
//
// Invalid certificate type
//
#define ERROR_IPSEC_IKE_INVALID_CERT_TYPE 13819L

//
// MessageId: ERROR_IPSEC_IKE_NO_PRIVATE_KEY
//
// MessageText:
//
// IKE negotiation failed because the machine certificate used does not have a private key. IPsec certificates require a private key. Contact your Network Security administrator about replacing with a certificate that has a private key.
//
#define ERROR_IPSEC_IKE_NO_PRIVATE_KEY   13820L

//
// MessageId: ERROR_IPSEC_IKE_DH_FAIL
//
// MessageText:
//
// Failure in Diffie-Helman computation
//
#define ERROR_IPSEC_IKE_DH_FAIL          13822L

//
// MessageId: ERROR_IPSEC_IKE_INVALID_HEADER
//
// MessageText:
//
// Invalid header
//
#define ERROR_IPSEC_IKE_INVALID_HEADER   13824L

//
// MessageId: ERROR_IPSEC_IKE_NO_POLICY
//
// MessageText:
//
// No policy configured
//
#define ERROR_IPSEC_IKE_NO_POLICY        13825L

//
// MessageId: ERROR_IPSEC_IKE_INVALID_SIGNATURE
//
// MessageText:
//
// Failed to verify signature
//
#define ERROR_IPSEC_IKE_INVALID_SIGNATURE 13826L

//
// MessageId: ERROR_IPSEC_IKE_KERBEROS_ERROR
//
// MessageText:
//
// Failed to authenticate using kerberos
//
#define ERROR_IPSEC_IKE_KERBEROS_ERROR   13827L

//
// MessageId: ERROR_IPSEC_IKE_NO_PUBLIC_KEY
//
// MessageText:
//
// Peer's certificate did not have a public key
//
#define ERROR_IPSEC_IKE_NO_PUBLIC_KEY    13828L

// These must stay as a unit.
//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR
//
// MessageText:
//
// Error processing error payload
//
#define ERROR_IPSEC_IKE_PROCESS_ERR      13829L

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_SA
//
// MessageText:
//
// Error processing SA payload
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_SA   13830L

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_PROP
//
// MessageText:
//
// Error processing Proposal payload
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_PROP 13831L

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_TRANS
//
// MessageText:
//
// Error processing Transform payload
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_TRANS 13832L

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_KE
//
// MessageText:
//
// Error processing KE payload
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_KE   13833L

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_ID
//
// MessageText:
//
// Error processing ID payload
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_ID   13834L

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_CERT
//
// MessageText:
//
// Error processing Cert payload
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_CERT 13835L

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_CERT_REQ
//
// MessageText:
//
// Error processing Certificate Request payload
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_CERT_REQ 13836L

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_HASH
//
// MessageText:
//
// Error processing Hash payload
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_HASH 13837L

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_SIG
//
// MessageText:
//
// Error processing Signature payload
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_SIG  13838L

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_NONCE
//
// MessageText:
//
// Error processing Nonce payload
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_NONCE 13839L

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_NOTIFY
//
// MessageText:
//
// Error processing Notify payload
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_NOTIFY 13840L

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_DELETE
//
// MessageText:
//
// Error processing Delete Payload
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_DELETE 13841L

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_VENDOR
//
// MessageText:
//
// Error processing VendorId payload
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_VENDOR 13842L

//
// MessageId: ERROR_IPSEC_IKE_INVALID_PAYLOAD
//
// MessageText:
//
// Invalid payload received
//
#define ERROR_IPSEC_IKE_INVALID_PAYLOAD  13843L

//
// MessageId: ERROR_IPSEC_IKE_LOAD_SOFT_SA
//
// MessageText:
//
// Soft SA loaded
//
#define ERROR_IPSEC_IKE_LOAD_SOFT_SA     13844L

//
// MessageId: ERROR_IPSEC_IKE_SOFT_SA_TORN_DOWN
//
// MessageText:
//
// Soft SA torn down
//
#define ERROR_IPSEC_IKE_SOFT_SA_TORN_DOWN 13845L

//
// MessageId: ERROR_IPSEC_IKE_INVALID_COOKIE
//
// MessageText:
//
// Invalid cookie received.
//
#define ERROR_IPSEC_IKE_INVALID_COOKIE   13846L

//
// MessageId: ERROR_IPSEC_IKE_NO_PEER_CERT
//
// MessageText:
//
// Peer failed to send valid machine certificate
//
#define ERROR_IPSEC_IKE_NO_PEER_CERT     13847L

//
// MessageId: ERROR_IPSEC_IKE_PEER_CRL_FAILED
//
// MessageText:
//
// Certification Revocation check of peer's certificate failed
//
#define ERROR_IPSEC_IKE_PEER_CRL_FAILED  13848L

//
// MessageId: ERROR_IPSEC_IKE_POLICY_CHANGE
//
// MessageText:
//
// New policy invalidated SAs formed with old policy
//
#define ERROR_IPSEC_IKE_POLICY_CHANGE    13849L

//
// MessageId: ERROR_IPSEC_IKE_NO_MM_POLICY
//
// MessageText:
//
// There is no available Main Mode IKE policy.
//
#define ERROR_IPSEC_IKE_NO_MM_POLICY     13850L

//
// MessageId: ERROR_IPSEC_IKE_NOTCBPRIV
//
// MessageText:
//
// Failed to enabled TCB privilege.
//
#define ERROR_IPSEC_IKE_NOTCBPRIV        13851L

//
// MessageId: ERROR_IPSEC_IKE_SECLOADFAIL
//
// MessageText:
//
// Failed to load SECURITY.DLL.
//
#define ERROR_IPSEC_IKE_SECLOADFAIL      13852L

//
// MessageId: ERROR_IPSEC_IKE_FAILSSPINIT
//
// MessageText:
//
// Failed to obtain security function table dispatch address from SSPI.
//
#define ERROR_IPSEC_IKE_FAILSSPINIT      13853L

//
// MessageId: ERROR_IPSEC_IKE_FAILQUERYSSP
//
// MessageText:
//
// Failed to query Kerberos package to obtain max token size.
//
#define ERROR_IPSEC_IKE_FAILQUERYSSP     13854L

//
// MessageId: ERROR_IPSEC_IKE_SRVACQFAIL
//
// MessageText:
//
// Failed to obtain Kerberos server credentials for ISAKMP/ERROR_IPSEC_IKE service. Kerberos authentication will not function. The most likely reason for this is lack of domain membership. This is normal if your computer is a member of a workgroup.
//
#define ERROR_IPSEC_IKE_SRVACQFAIL       13855L

//
// MessageId: ERROR_IPSEC_IKE_SRVQUERYCRED
//
// MessageText:
//
// Failed to determine SSPI principal name for ISAKMP/ERROR_IPSEC_IKE service (QueryCredentialsAttributes).
//
#define ERROR_IPSEC_IKE_SRVQUERYCRED     13856L

//
// MessageId: ERROR_IPSEC_IKE_GETSPIFAIL
//
// MessageText:
//
// Failed to obtain new SPI for the inbound SA from Ipsec driver. The most common cause for this is that the driver does not have the correct filter. Check your policy to verify the filters.
//
#define ERROR_IPSEC_IKE_GETSPIFAIL       13857L

//
// MessageId: ERROR_IPSEC_IKE_INVALID_FILTER
//
// MessageText:
//
// Given filter is invalid
//
#define ERROR_IPSEC_IKE_INVALID_FILTER   13858L

//
// MessageId: ERROR_IPSEC_IKE_OUT_OF_MEMORY
//
// MessageText:
//
// Memory allocation failed.
//
#define ERROR_IPSEC_IKE_OUT_OF_MEMORY    13859L

//
// MessageId: ERROR_IPSEC_IKE_ADD_UPDATE_KEY_FAILED
//
// MessageText:
//
// Failed to add Security Association to IPSec Driver. The most common cause for this is if the IKE negotiation took too long to complete. If the problem persists, reduce the load on the faulting machine.
//
#define ERROR_IPSEC_IKE_ADD_UPDATE_KEY_FAILED 13860L

//
// MessageId: ERROR_IPSEC_IKE_INVALID_POLICY
//
// MessageText:
//
// Invalid policy
//
#define ERROR_IPSEC_IKE_INVALID_POLICY   13861L

//
// MessageId: ERROR_IPSEC_IKE_UNKNOWN_DOI
//
// MessageText:
//
// Invalid DOI
//
#define ERROR_IPSEC_IKE_UNKNOWN_DOI      13862L

//
// MessageId: ERROR_IPSEC_IKE_INVALID_SITUATION
//
// MessageText:
//
// Invalid situation
//
#define ERROR_IPSEC_IKE_INVALID_SITUATION 13863L

//
// MessageId: ERROR_IPSEC_IKE_DH_FAILURE
//
// MessageText:
//
// Diffie-Hellman failure
//
#define ERROR_IPSEC_IKE_DH_FAILURE       13864L

//
// MessageId: ERROR_IPSEC_IKE_INVALID_GROUP
//
// MessageText:
//
// Invalid Diffie-Hellman group
//
#define ERROR_IPSEC_IKE_INVALID_GROUP    13865L

//
// MessageId: ERROR_IPSEC_IKE_ENCRYPT
//
// MessageText:
//
// Error encrypting payload
//
#define ERROR_IPSEC_IKE_ENCRYPT          13866L

//
// MessageId: ERROR_IPSEC_IKE_DECRYPT
//
// MessageText:
//
// Error decrypting payload
//
#define ERROR_IPSEC_IKE_DECRYPT          13867L

//
// MessageId: ERROR_IPSEC_IKE_POLICY_MATCH
//
// MessageText:
//
// Policy match error
//
#define ERROR_IPSEC_IKE_POLICY_MATCH     13868L

//
// MessageId: ERROR_IPSEC_IKE_UNSUPPORTED_ID
//
// MessageText:
//
// Unsupported ID
//
#define ERROR_IPSEC_IKE_UNSUPPORTED_ID   13869L

//
// MessageId: ERROR_IPSEC_IKE_INVALID_HASH
//
// MessageText:
//
// Hash verification failed
//
#define ERROR_IPSEC_IKE_INVALID_HASH     13870L

//
// MessageId: ERROR_IPSEC_IKE_INVALID_HASH_ALG
//
// MessageText:
//
// Invalid hash algorithm
//
#define ERROR_IPSEC_IKE_INVALID_HASH_ALG 13871L

//
// MessageId: ERROR_IPSEC_IKE_INVALID_HASH_SIZE
//
// MessageText:
//
// Invalid hash size
//
#define ERROR_IPSEC_IKE_INVALID_HASH_SIZE 13872L

//
// MessageId: ERROR_IPSEC_IKE_INVALID_ENCRYPT_ALG
//
// MessageText:
//
// Invalid encryption algorithm
//
#define ERROR_IPSEC_IKE_INVALID_ENCRYPT_ALG 13873L

//
// MessageId: ERROR_IPSEC_IKE_INVALID_AUTH_ALG
//
// MessageText:
//
// Invalid authentication algorithm
//
#define ERROR_IPSEC_IKE_INVALID_AUTH_ALG 13874L

//
// MessageId: ERROR_IPSEC_IKE_INVALID_SIG
//
// MessageText:
//
// Invalid certificate signature
//
#define ERROR_IPSEC_IKE_INVALID_SIG      13875L

//
// MessageId: ERROR_IPSEC_IKE_LOAD_FAILED
//
// MessageText:
//
// Load failed
//
#define ERROR_IPSEC_IKE_LOAD_FAILED      13876L

//
// MessageId: ERROR_IPSEC_IKE_RPC_DELETE
//
// MessageText:
//
// Deleted via RPC call
//
#define ERROR_IPSEC_IKE_RPC_DELETE       13877L

//
// MessageId: ERROR_IPSEC_IKE_BENIGN_REINIT
//
// MessageText:
//
// Temporary state created to perform reinit. This is not a real failure.
//
#define ERROR_IPSEC_IKE_BENIGN_REINIT    13878L

//
// MessageId: ERROR_IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY
//
// MessageText:
//
// The lifetime value received in the Responder Lifetime Notify is below the Windows 2000 configured minimum value. Please fix the policy on the peer machine.
//
#define ERROR_IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY 13879L

//
// MessageId: ERROR_IPSEC_IKE_INVALID_CERT_KEYLEN
//
// MessageText:
//
// Key length in certificate is too small for configured security requirements.
//
#define ERROR_IPSEC_IKE_INVALID_CERT_KEYLEN 13881L

//
// MessageId: ERROR_IPSEC_IKE_MM_LIMIT
//
// MessageText:
//
// Max number of established MM SAs to peer exceeded.
//
#define ERROR_IPSEC_IKE_MM_LIMIT         13882L

//
// MessageId: ERROR_IPSEC_IKE_NEGOTIATION_DISABLED
//
// MessageText:
//
// IKE received a policy that disables negotiation.
//
#define ERROR_IPSEC_IKE_NEGOTIATION_DISABLED 13883L

//
// MessageId: ERROR_IPSEC_IKE_QM_LIMIT
//
// MessageText:
//
// Reached maximum quick mode limit for the main mode. New main mode will be started.
//
#define ERROR_IPSEC_IKE_QM_LIMIT         13884L

//
// MessageId: ERROR_IPSEC_IKE_MM_EXPIRED
//
// MessageText:
//
// Main mode SA lifetime expired or peer sent a main mode delete.
//
#define ERROR_IPSEC_IKE_MM_EXPIRED       13885L

//
// MessageId: ERROR_IPSEC_IKE_PEER_MM_ASSUMED_INVALID
//
// MessageText:
//
// Main mode SA assumed to be invalid because peer stopped responding.
//
#define ERROR_IPSEC_IKE_PEER_MM_ASSUMED_INVALID 13886L

//
// MessageId: ERROR_IPSEC_IKE_CERT_CHAIN_POLICY_MISMATCH
//
// MessageText:
//
// Certificate doesn't chain to a trusted root in IPsec policy.
//
#define ERROR_IPSEC_IKE_CERT_CHAIN_POLICY_MISMATCH 13887L

//
// MessageId: ERROR_IPSEC_IKE_UNEXPECTED_MESSAGE_ID
//
// MessageText:
//
// Received unexpected message ID.
//
#define ERROR_IPSEC_IKE_UNEXPECTED_MESSAGE_ID 13888L

//
// MessageId: ERROR_IPSEC_IKE_INVALID_AUTH_PAYLOAD
//
// MessageText:
//
// Received invalid authentication offers.
//
#define ERROR_IPSEC_IKE_INVALID_AUTH_PAYLOAD 13889L

//
// MessageId: ERROR_IPSEC_IKE_DOS_COOKIE_SENT
//
// MessageText:
//
// Sent DOS cookie notify to intiator.
//
#define ERROR_IPSEC_IKE_DOS_COOKIE_SENT  13890L

//
// MessageId: ERROR_IPSEC_IKE_SHUTTING_DOWN
//
// MessageText:
//
// IKE service is shutting down.
//
#define ERROR_IPSEC_IKE_SHUTTING_DOWN    13891L

//
// MessageId: ERROR_IPSEC_IKE_CGA_AUTH_FAILED
//
// MessageText:
//
// Could not verify binding between CGA address and certificate.
//
#define ERROR_IPSEC_IKE_CGA_AUTH_FAILED  13892L

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_NATOA
//
// MessageText:
//
// Error processing NatOA payload.
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_NATOA 13893L

//
// MessageId: ERROR_IPSEC_IKE_INVALID_MM_FOR_QM
//
// MessageText:
//
// Parameters of the main mode are invalid for this quick mode.
//
#define ERROR_IPSEC_IKE_INVALID_MM_FOR_QM 13894L

//
// MessageId: ERROR_IPSEC_IKE_QM_EXPIRED
//
// MessageText:
//
// Quick mode SA was expired by IPsec driver.
//
#define ERROR_IPSEC_IKE_QM_EXPIRED       13895L

//
// MessageId: ERROR_IPSEC_IKE_TOO_MANY_FILTERS
//
// MessageText:
//
// Too many dynamically added IKEEXT filters were detected.
//
#define ERROR_IPSEC_IKE_TOO_MANY_FILTERS 13896L

//
// MessageId: ERROR_IPSEC_IKE_NEG_STATUS_END
//
// MessageText:
//
//  ERROR_IPSEC_IKE_NEG_STATUS_END
//
#define ERROR_IPSEC_IKE_NEG_STATUS_END   13897L

//
// Following error codes are returned by IPsec kernel.
//
//
// MessageId: ERROR_IPSEC_BAD_SPI
//
// MessageText:
//
// The SPI in the packet does not match a valid IPsec SA.
//
#define ERROR_IPSEC_BAD_SPI              13910L

//
// MessageId: ERROR_IPSEC_SA_LIFETIME_EXPIRED
//
// MessageText:
//
// Packet was received on an IPsec SA whose lifetime has expired.
//
#define ERROR_IPSEC_SA_LIFETIME_EXPIRED  13911L

//
// MessageId: ERROR_IPSEC_WRONG_SA
//
// MessageText:
//
// Packet was received on an IPsec SA that doesn't match the packet characteristics.
//
#define ERROR_IPSEC_WRONG_SA             13912L

//
// MessageId: ERROR_IPSEC_REPLAY_CHECK_FAILED
//
// MessageText:
//
// Packet sequence number replay check failed.
//
#define ERROR_IPSEC_REPLAY_CHECK_FAILED  13913L

//
// MessageId: ERROR_IPSEC_INVALID_PACKET
//
// MessageText:
//
// IPsec header and/or trailer in the packet is invalid.
//
#define ERROR_IPSEC_INVALID_PACKET       13914L

//
// MessageId: ERROR_IPSEC_INTEGRITY_CHECK_FAILED
//
// MessageText:
//
// IPsec integrity check failed.
//
#define ERROR_IPSEC_INTEGRITY_CHECK_FAILED 13915L

//
// MessageId: ERROR_IPSEC_CLEAR_TEXT_DROP
//
// MessageText:
//
// IPsec dropped a clear text packet.
//
#define ERROR_IPSEC_CLEAR_TEXT_DROP      13916L


///////////////////////////////////////////////////
//                                               //
//           End of IPSec Error codes            //
//                                               //
//                 13000 to 13999                //
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//                                               //
//         Start of Side By Side Error Codes     //
//                                               //
//                 14000 to 14999                //
///////////////////////////////////////////////////

//
// MessageId: ERROR_SXS_SECTION_NOT_FOUND
//
// MessageText:
//
// The requested section was not present in the activation context.
//
#define ERROR_SXS_SECTION_NOT_FOUND      14000L

//
// MessageId: ERROR_SXS_CANT_GEN_ACTCTX
//
// MessageText:
//
// The application has failed to start because its side-by-side configuration is incorrect. Please see the application event log for more detail.
//
#define ERROR_SXS_CANT_GEN_ACTCTX        14001L

//
// MessageId: ERROR_SXS_INVALID_ACTCTXDATA_FORMAT
//
// MessageText:
//
// The application binding data format is invalid.
//
#define ERROR_SXS_INVALID_ACTCTXDATA_FORMAT 14002L

//
// MessageId: ERROR_SXS_ASSEMBLY_NOT_FOUND
//
// MessageText:
//
// The referenced assembly is not installed on your system.
//
#define ERROR_SXS_ASSEMBLY_NOT_FOUND     14003L

//
// MessageId: ERROR_SXS_MANIFEST_FORMAT_ERROR
//
// MessageText:
//
// The manifest file does not begin with the required tag and format information.
//
#define ERROR_SXS_MANIFEST_FORMAT_ERROR  14004L

//
// MessageId: ERROR_SXS_MANIFEST_PARSE_ERROR
//
// MessageText:
//
// The manifest file contains one or more syntax errors.
//
#define ERROR_SXS_MANIFEST_PARSE_ERROR   14005L

//
// MessageId: ERROR_SXS_ACTIVATION_CONTEXT_DISABLED
//
// MessageText:
//
// The application attempted to activate a disabled activation context.
//
#define ERROR_SXS_ACTIVATION_CONTEXT_DISABLED 14006L

//
// MessageId: ERROR_SXS_KEY_NOT_FOUND
//
// MessageText:
//
// The requested lookup key was not found in any active activation context.
//
#define ERROR_SXS_KEY_NOT_FOUND          14007L

//
// MessageId: ERROR_SXS_VERSION_CONFLICT
//
// MessageText:
//
// A component version required by the application conflicts with another component version already active.
//
#define ERROR_SXS_VERSION_CONFLICT       14008L

//
// MessageId: ERROR_SXS_WRONG_SECTION_TYPE
//
// MessageText:
//
// The type requested activation context section does not match the query API used.
//
#define ERROR_SXS_WRONG_SECTION_TYPE     14009L

//
// MessageId: ERROR_SXS_THREAD_QUERIES_DISABLED
//
// MessageText:
//
// Lack of system resources has required isolated activation to be disabled for the current thread of execution.
//
#define ERROR_SXS_THREAD_QUERIES_DISABLED 14010L

//
// MessageId: ERROR_SXS_PROCESS_DEFAULT_ALREADY_SET
//
// MessageText:
//
// An attempt to set the process default activation context failed because the process default activation context was already set.
//
#define ERROR_SXS_PROCESS_DEFAULT_ALREADY_SET 14011L

//
// MessageId: ERROR_SXS_UNKNOWN_ENCODING_GROUP
//
// MessageText:
//
// The encoding group identifier specified is not recognized.
//
#define ERROR_SXS_UNKNOWN_ENCODING_GROUP 14012L

//
// MessageId: ERROR_SXS_UNKNOWN_ENCODING
//
// MessageText:
//
// The encoding requested is not recognized.
//
#define ERROR_SXS_UNKNOWN_ENCODING       14013L

//
// MessageId: ERROR_SXS_INVALID_XML_NAMESPACE_URI
//
// MessageText:
//
// The manifest contains a reference to an invalid URI.
//
#define ERROR_SXS_INVALID_XML_NAMESPACE_URI 14014L

//
// MessageId: ERROR_SXS_ROOT_MANIFEST_DEPENDENCY_NOT_INSTALLED
//
// MessageText:
//
// The application manifest contains a reference to a dependent assembly which is not installed
//
#define ERROR_SXS_ROOT_MANIFEST_DEPENDENCY_NOT_INSTALLED 14015L

//
// MessageId: ERROR_SXS_LEAF_MANIFEST_DEPENDENCY_NOT_INSTALLED
//
// MessageText:
//
// The manifest for an assembly used by the application has a reference to a dependent assembly which is not installed
//
#define ERROR_SXS_LEAF_MANIFEST_DEPENDENCY_NOT_INSTALLED 14016L

//
// MessageId: ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE
//
// MessageText:
//
// The manifest contains an attribute for the assembly identity which is not valid.
//
#define ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE 14017L

//
// MessageId: ERROR_SXS_MANIFEST_MISSING_REQUIRED_DEFAULT_NAMESPACE
//
// MessageText:
//
// The manifest is missing the required default namespace specification on the assembly element.
//
#define ERROR_SXS_MANIFEST_MISSING_REQUIRED_DEFAULT_NAMESPACE 14018L

//
// MessageId: ERROR_SXS_MANIFEST_INVALID_REQUIRED_DEFAULT_NAMESPACE
//
// MessageText:
//
// The manifest has a default namespace specified on the assembly element but its value is not "urn:schemas-microsoft-com:asm.v1".
//
#define ERROR_SXS_MANIFEST_INVALID_REQUIRED_DEFAULT_NAMESPACE 14019L

//
// MessageId: ERROR_SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT
//
// MessageText:
//
// The private manifest probed has crossed reparse-point-associated path
//
#define ERROR_SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT 14020L

//
// MessageId: ERROR_SXS_DUPLICATE_DLL_NAME
//
// MessageText:
//
// Two or more components referenced directly or indirectly by the application manifest have files by the same name.
//
#define ERROR_SXS_DUPLICATE_DLL_NAME     14021L

//
// MessageId: ERROR_SXS_DUPLICATE_WINDOWCLASS_NAME
//
// MessageText:
//
// Two or more components referenced directly or indirectly by the application manifest have window classes with the same name.
//
#define ERROR_SXS_DUPLICATE_WINDOWCLASS_NAME 14022L

//
// MessageId: ERROR_SXS_DUPLICATE_CLSID
//
// MessageText:
//
// Two or more components referenced directly or indirectly by the application manifest have the same COM server CLSIDs.
//
#define ERROR_SXS_DUPLICATE_CLSID        14023L

//
// MessageId: ERROR_SXS_DUPLICATE_IID
//
// MessageText:
//
// Two or more components referenced directly or indirectly by the application manifest have proxies for the same COM interface IIDs.
//
#define ERROR_SXS_DUPLICATE_IID          14024L

//
// MessageId: ERROR_SXS_DUPLICATE_TLBID
//
// MessageText:
//
// Two or more components referenced directly or indirectly by the application manifest have the same COM type library TLBIDs.
//
#define ERROR_SXS_DUPLICATE_TLBID        14025L

//
// MessageId: ERROR_SXS_DUPLICATE_PROGID
//
// MessageText:
//
// Two or more components referenced directly or indirectly by the application manifest have the same COM ProgIDs.
//
#define ERROR_SXS_DUPLICATE_PROGID       14026L

//
// MessageId: ERROR_SXS_DUPLICATE_ASSEMBLY_NAME
//
// MessageText:
//
// Two or more components referenced directly or indirectly by the application manifest are different versions of the same component which is not permitted.
//
#define ERROR_SXS_DUPLICATE_ASSEMBLY_NAME 14027L

//
// MessageId: ERROR_SXS_FILE_HASH_MISMATCH
//
// MessageText:
//
// A component's file does not match the verification information present in the component manifest.
//
#define ERROR_SXS_FILE_HASH_MISMATCH     14028L

//
// MessageId: ERROR_SXS_POLICY_PARSE_ERROR
//
// MessageText:
//
// The policy manifest contains one or more syntax errors.
//
#define ERROR_SXS_POLICY_PARSE_ERROR     14029L

//
// MessageId: ERROR_SXS_XML_E_MISSINGQUOTE
//
// MessageText:
//
// Manifest Parse Error : A string literal was expected, but no opening quote character was found.
//
#define ERROR_SXS_XML_E_MISSINGQUOTE     14030L

//
// MessageId: ERROR_SXS_XML_E_COMMENTSYNTAX
//
// MessageText:
//
// Manifest Parse Error : Incorrect syntax was used in a comment.
//
#define ERROR_SXS_XML_E_COMMENTSYNTAX    14031L

//
// MessageId: ERROR_SXS_XML_E_BADSTARTNAMECHAR
//
// MessageText:
//
// Manifest Parse Error : A name was started with an invalid character.
//
#define ERROR_SXS_XML_E_BADSTARTNAMECHAR 14032L

//
// MessageId: ERROR_SXS_XML_E_BADNAMECHAR
//
// MessageText:
//
// Manifest Parse Error : A name contained an invalid character.
//
#define ERROR_SXS_XML_E_BADNAMECHAR      14033L

//
// MessageId: ERROR_SXS_XML_E_BADCHARINSTRING
//
// MessageText:
//
// Manifest Parse Error : A string literal contained an invalid character.
//
#define ERROR_SXS_XML_E_BADCHARINSTRING  14034L

//
// MessageId: ERROR_SXS_XML_E_XMLDECLSYNTAX
//
// MessageText:
//
// Manifest Parse Error : Invalid syntax for an xml declaration.
//
#define ERROR_SXS_XML_E_XMLDECLSYNTAX    14035L

//
// MessageId: ERROR_SXS_XML_E_BADCHARDATA
//
// MessageText:
//
// Manifest Parse Error : An Invalid character was found in text content.
//
#define ERROR_SXS_XML_E_BADCHARDATA      14036L

//
// MessageId: ERROR_SXS_XML_E_MISSINGWHITESPACE
//
// MessageText:
//
// Manifest Parse Error : Required white space was missing.
//
#define ERROR_SXS_XML_E_MISSINGWHITESPACE 14037L

//
// MessageId: ERROR_SXS_XML_E_EXPECTINGTAGEND
//
// MessageText:
//
// Manifest Parse Error : The character '>' was expected.
//
#define ERROR_SXS_XML_E_EXPECTINGTAGEND  14038L

//
// MessageId: ERROR_SXS_XML_E_MISSINGSEMICOLON
//
// MessageText:
//
// Manifest Parse Error : A semi colon character was expected.
//
#define ERROR_SXS_XML_E_MISSINGSEMICOLON 14039L

//
// MessageId: ERROR_SXS_XML_E_UNBALANCEDPAREN
//
// MessageText:
//
// Manifest Parse Error : Unbalanced parentheses.
//
#define ERROR_SXS_XML_E_UNBALANCEDPAREN  14040L

//
// MessageId: ERROR_SXS_XML_E_INTERNALERROR
//
// MessageText:
//
// Manifest Parse Error : Internal error.
//
#define ERROR_SXS_XML_E_INTERNALERROR    14041L

//
// MessageId: ERROR_SXS_XML_E_UNEXPECTED_WHITESPACE
//
// MessageText:
//
// Manifest Parse Error : Whitespace is not allowed at this location.
//
#define ERROR_SXS_XML_E_UNEXPECTED_WHITESPACE 14042L

//
// MessageId: ERROR_SXS_XML_E_INCOMPLETE_ENCODING
//
// MessageText:
//
// Manifest Parse Error : End of file reached in invalid state for current encoding.
//
#define ERROR_SXS_XML_E_INCOMPLETE_ENCODING 14043L

//
// MessageId: ERROR_SXS_XML_E_MISSING_PAREN
//
// MessageText:
//
// Manifest Parse Error : Missing parenthesis.
//
#define ERROR_SXS_XML_E_MISSING_PAREN    14044L

//
// MessageId: ERROR_SXS_XML_E_EXPECTINGCLOSEQUOTE
//
// MessageText:
//
// Manifest Parse Error : A single or double closing quote character (\' or \") is missing.
//
#define ERROR_SXS_XML_E_EXPECTINGCLOSEQUOTE 14045L

//
// MessageId: ERROR_SXS_XML_E_MULTIPLE_COLONS
//
// MessageText:
//
// Manifest Parse Error : Multiple colons are not allowed in a name.
//
#define ERROR_SXS_XML_E_MULTIPLE_COLONS  14046L

//
// MessageId: ERROR_SXS_XML_E_INVALID_DECIMAL
//
// MessageText:
//
// Manifest Parse Error : Invalid character for decimal digit.
//
#define ERROR_SXS_XML_E_INVALID_DECIMAL  14047L

//
// MessageId: ERROR_SXS_XML_E_INVALID_HEXIDECIMAL
//
// MessageText:
//
// Manifest Parse Error : Invalid character for hexidecimal digit.
//
#define ERROR_SXS_XML_E_INVALID_HEXIDECIMAL 14048L

//
// MessageId: ERROR_SXS_XML_E_INVALID_UNICODE
//
// MessageText:
//
// Manifest Parse Error : Invalid unicode character value for this platform.
//
#define ERROR_SXS_XML_E_INVALID_UNICODE  14049L

//
// MessageId: ERROR_SXS_XML_E_WHITESPACEORQUESTIONMARK
//
// MessageText:
//
// Manifest Parse Error : Expecting whitespace or '?'.
//
#define ERROR_SXS_XML_E_WHITESPACEORQUESTIONMARK 14050L

//
// MessageId: ERROR_SXS_XML_E_UNEXPECTEDENDTAG
//
// MessageText:
//
// Manifest Parse Error : End tag was not expected at this location.
//
#define ERROR_SXS_XML_E_UNEXPECTEDENDTAG 14051L

//
// MessageId: ERROR_SXS_XML_E_UNCLOSEDTAG
//
// MessageText:
//
// Manifest Parse Error : The following tags were not closed: %1.
//
#define ERROR_SXS_XML_E_UNCLOSEDTAG      14052L

//
// MessageId: ERROR_SXS_XML_E_DUPLICATEATTRIBUTE
//
// MessageText:
//
// Manifest Parse Error : Duplicate attribute.
//
#define ERROR_SXS_XML_E_DUPLICATEATTRIBUTE 14053L

//
// MessageId: ERROR_SXS_XML_E_MULTIPLEROOTS
//
// MessageText:
//
// Manifest Parse Error : Only one top level element is allowed in an XML document.
//
#define ERROR_SXS_XML_E_MULTIPLEROOTS    14054L

//
// MessageId: ERROR_SXS_XML_E_INVALIDATROOTLEVEL
//
// MessageText:
//
// Manifest Parse Error : Invalid at the top level of the document.
//
#define ERROR_SXS_XML_E_INVALIDATROOTLEVEL 14055L

//
// MessageId: ERROR_SXS_XML_E_BADXMLDECL
//
// MessageText:
//
// Manifest Parse Error : Invalid xml declaration.
//
#define ERROR_SXS_XML_E_BADXMLDECL       14056L

//
// MessageId: ERROR_SXS_XML_E_MISSINGROOT
//
// MessageText:
//
// Manifest Parse Error : XML document must have a top level element.
//
#define ERROR_SXS_XML_E_MISSINGROOT      14057L

//
// MessageId: ERROR_SXS_XML_E_UNEXPECTEDEOF
//
// MessageText:
//
// Manifest Parse Error : Unexpected end of file.
//
#define ERROR_SXS_XML_E_UNEXPECTEDEOF    14058L

//
// MessageId: ERROR_SXS_XML_E_BADPEREFINSUBSET
//
// MessageText:
//
// Manifest Parse Error : Parameter entities cannot be used inside markup declarations in an internal subset.
//
#define ERROR_SXS_XML_E_BADPEREFINSUBSET 14059L

//
// MessageId: ERROR_SXS_XML_E_UNCLOSEDSTARTTAG
//
// MessageText:
//
// Manifest Parse Error : Element was not closed.
//
#define ERROR_SXS_XML_E_UNCLOSEDSTARTTAG 14060L

//
// MessageId: ERROR_SXS_XML_E_UNCLOSEDENDTAG
//
// MessageText:
//
// Manifest Parse Error : End element was missing the character '>'.
//
#define ERROR_SXS_XML_E_UNCLOSEDENDTAG   14061L

//
// MessageId: ERROR_SXS_XML_E_UNCLOSEDSTRING
//
// MessageText:
//
// Manifest Parse Error : A string literal was not closed.
//
#define ERROR_SXS_XML_E_UNCLOSEDSTRING   14062L

//
// MessageId: ERROR_SXS_XML_E_UNCLOSEDCOMMENT
//
// MessageText:
//
// Manifest Parse Error : A comment was not closed.
//
#define ERROR_SXS_XML_E_UNCLOSEDCOMMENT  14063L

//
// MessageId: ERROR_SXS_XML_E_UNCLOSEDDECL
//
// MessageText:
//
// Manifest Parse Error : A declaration was not closed.
//
#define ERROR_SXS_XML_E_UNCLOSEDDECL     14064L

//
// MessageId: ERROR_SXS_XML_E_UNCLOSEDCDATA
//
// MessageText:
//
// Manifest Parse Error : A CDATA section was not closed.
//
#define ERROR_SXS_XML_E_UNCLOSEDCDATA    14065L

//
// MessageId: ERROR_SXS_XML_E_RESERVEDNAMESPACE
//
// MessageText:
//
// Manifest Parse Error : The namespace prefix is not allowed to start with the reserved string "xml".
//
#define ERROR_SXS_XML_E_RESERVEDNAMESPACE 14066L

//
// MessageId: ERROR_SXS_XML_E_INVALIDENCODING
//
// MessageText:
//
// Manifest Parse Error : System does not support the specified encoding.
//
#define ERROR_SXS_XML_E_INVALIDENCODING  14067L

//
// MessageId: ERROR_SXS_XML_E_INVALIDSWITCH
//
// MessageText:
//
// Manifest Parse Error : Switch from current encoding to specified encoding not supported.
//
#define ERROR_SXS_XML_E_INVALIDSWITCH    14068L

//
// MessageId: ERROR_SXS_XML_E_BADXMLCASE
//
// MessageText:
//
// Manifest Parse Error : The name 'xml' is reserved and must be lower case.
//
#define ERROR_SXS_XML_E_BADXMLCASE       14069L

//
// MessageId: ERROR_SXS_XML_E_INVALID_STANDALONE
//
// MessageText:
//
// Manifest Parse Error : The standalone attribute must have the value 'yes' or 'no'.
//
#define ERROR_SXS_XML_E_INVALID_STANDALONE 14070L

//
// MessageId: ERROR_SXS_XML_E_UNEXPECTED_STANDALONE
//
// MessageText:
//
// Manifest Parse Error : The standalone attribute cannot be used in external entities.
//
#define ERROR_SXS_XML_E_UNEXPECTED_STANDALONE 14071L

//
// MessageId: ERROR_SXS_XML_E_INVALID_VERSION
//
// MessageText:
//
// Manifest Parse Error : Invalid version number.
//
#define ERROR_SXS_XML_E_INVALID_VERSION  14072L

//
// MessageId: ERROR_SXS_XML_E_MISSINGEQUALS
//
// MessageText:
//
// Manifest Parse Error : Missing equals sign between attribute and attribute value.
//
#define ERROR_SXS_XML_E_MISSINGEQUALS    14073L

//
// MessageId: ERROR_SXS_PROTECTION_RECOVERY_FAILED
//
// MessageText:
//
// Assembly Protection Error : Unable to recover the specified assembly.
//
#define ERROR_SXS_PROTECTION_RECOVERY_FAILED 14074L

//
// MessageId: ERROR_SXS_PROTECTION_PUBLIC_KEY_TOO_SHORT
//
// MessageText:
//
// Assembly Protection Error : The public key for an assembly was too short to be allowed.
//
#define ERROR_SXS_PROTECTION_PUBLIC_KEY_TOO_SHORT 14075L

//
// MessageId: ERROR_SXS_PROTECTION_CATALOG_NOT_VALID
//
// MessageText:
//
// Assembly Protection Error : The catalog for an assembly is not valid, or does not match the assembly's manifest.
//
#define ERROR_SXS_PROTECTION_CATALOG_NOT_VALID 14076L

//
// MessageId: ERROR_SXS_UNTRANSLATABLE_HRESULT
//
// MessageText:
//
// An HRESULT could not be translated to a corresponding Win32 error code.
//
#define ERROR_SXS_UNTRANSLATABLE_HRESULT 14077L

//
// MessageId: ERROR_SXS_PROTECTION_CATALOG_FILE_MISSING
//
// MessageText:
//
// Assembly Protection Error : The catalog for an assembly is missing.
//
#define ERROR_SXS_PROTECTION_CATALOG_FILE_MISSING 14078L

//
// MessageId: ERROR_SXS_MISSING_ASSEMBLY_IDENTITY_ATTRIBUTE
//
// MessageText:
//
// The supplied assembly identity is missing one or more attributes which must be present in this context.
//
#define ERROR_SXS_MISSING_ASSEMBLY_IDENTITY_ATTRIBUTE 14079L

//
// MessageId: ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE_NAME
//
// MessageText:
//
// The supplied assembly identity has one or more attribute names that contain characters not permitted in XML names.
//
#define ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE_NAME 14080L

//
// MessageId: ERROR_SXS_ASSEMBLY_MISSING
//
// MessageText:
//
// The referenced assembly could not be found.
//
#define ERROR_SXS_ASSEMBLY_MISSING       14081L

//
// MessageId: ERROR_SXS_CORRUPT_ACTIVATION_STACK
//
// MessageText:
//
// The activation context activation stack for the running thread of execution is corrupt.
//
#define ERROR_SXS_CORRUPT_ACTIVATION_STACK 14082L

//
// MessageId: ERROR_SXS_CORRUPTION
//
// MessageText:
//
// The application isolation metadata for this process or thread has become corrupt.
//
#define ERROR_SXS_CORRUPTION             14083L

//
// MessageId: ERROR_SXS_EARLY_DEACTIVATION
//
// MessageText:
//
// The activation context being deactivated is not the most recently activated one.
//
#define ERROR_SXS_EARLY_DEACTIVATION     14084L

//
// MessageId: ERROR_SXS_INVALID_DEACTIVATION
//
// MessageText:
//
// The activation context being deactivated is not active for the current thread of execution.
//
#define ERROR_SXS_INVALID_DEACTIVATION   14085L

//
// MessageId: ERROR_SXS_MULTIPLE_DEACTIVATION
//
// MessageText:
//
// The activation context being deactivated has already been deactivated.
//
#define ERROR_SXS_MULTIPLE_DEACTIVATION  14086L

//
// MessageId: ERROR_SXS_PROCESS_TERMINATION_REQUESTED
//
// MessageText:
//
// A component used by the isolation facility has requested to terminate the process.
//
#define ERROR_SXS_PROCESS_TERMINATION_REQUESTED 14087L

//
// MessageId: ERROR_SXS_RELEASE_ACTIVATION_CONTEXT
//
// MessageText:
//
// A kernel mode component is releasing a reference on an activation context.
//
#define ERROR_SXS_RELEASE_ACTIVATION_CONTEXT 14088L

//
// MessageId: ERROR_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY
//
// MessageText:
//
// The activation context of system default assembly could not be generated.
//
#define ERROR_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY 14089L

//
// MessageId: ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE
//
// MessageText:
//
// The value of an attribute in an identity is not within the legal range.
//
#define ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE 14090L

//
// MessageId: ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME
//
// MessageText:
//
// The name of an attribute in an identity is not within the legal range.
//
#define ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME 14091L

//
// MessageId: ERROR_SXS_IDENTITY_DUPLICATE_ATTRIBUTE
//
// MessageText:
//
// An identity contains two definitions for the same attribute.
//
#define ERROR_SXS_IDENTITY_DUPLICATE_ATTRIBUTE 14092L

//
// MessageId: ERROR_SXS_IDENTITY_PARSE_ERROR
//
// MessageText:
//
// The identity string is malformed. This may be due to a trailing comma, more than two unnamed attributes, missing attribute name or missing attribute value.
//
#define ERROR_SXS_IDENTITY_PARSE_ERROR   14093L

//
// MessageId: ERROR_MALFORMED_SUBSTITUTION_STRING
//
// MessageText:
//
// A string containing localized substitutable content was malformed. Either a dollar sign ($) was follwed by something other than a left parenthesis or another dollar sign or an substitution's right parenthesis was not found.
//
#define ERROR_MALFORMED_SUBSTITUTION_STRING 14094L

//
// MessageId: ERROR_SXS_INCORRECT_PUBLIC_KEY_TOKEN
//
// MessageText:
//
// The public key token does not correspond to the public key specified.
//
#define ERROR_SXS_INCORRECT_PUBLIC_KEY_TOKEN 14095L

//
// MessageId: ERROR_UNMAPPED_SUBSTITUTION_STRING
//
// MessageText:
//
// A substitution string had no mapping.
//
#define ERROR_UNMAPPED_SUBSTITUTION_STRING 14096L

//
// MessageId: ERROR_SXS_ASSEMBLY_NOT_LOCKED
//
// MessageText:
//
// The component must be locked before making the request.
//
#define ERROR_SXS_ASSEMBLY_NOT_LOCKED    14097L

//
// MessageId: ERROR_SXS_COMPONENT_STORE_CORRUPT
//
// MessageText:
//
// The component store has been corrupted.
//
#define ERROR_SXS_COMPONENT_STORE_CORRUPT 14098L

//
// MessageId: ERROR_ADVANCED_INSTALLER_FAILED
//
// MessageText:
//
// An advanced installer failed during setup or servicing.
//
#define ERROR_ADVANCED_INSTALLER_FAILED  14099L

//
// MessageId: ERROR_XML_ENCODING_MISMATCH
//
// MessageText:
//
// The character encoding in the XML declaration did not match the encoding used in the document.
//
#define ERROR_XML_ENCODING_MISMATCH      14100L

//
// MessageId: ERROR_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT
//
// MessageText:
//
// The identities of the manifests are identical but their contents are different.
//
#define ERROR_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT 14101L

//
// MessageId: ERROR_SXS_IDENTITIES_DIFFERENT
//
// MessageText:
//
// The component identities are different.
//
#define ERROR_SXS_IDENTITIES_DIFFERENT   14102L

//
// MessageId: ERROR_SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT
//
// MessageText:
//
// The assembly is not a deployment.
//
#define ERROR_SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT 14103L

//
// MessageId: ERROR_SXS_FILE_NOT_PART_OF_ASSEMBLY
//
// MessageText:
//
// The file is not a part of the assembly.
//
#define ERROR_SXS_FILE_NOT_PART_OF_ASSEMBLY 14104L

//
// MessageId: ERROR_SXS_MANIFEST_TOO_BIG
//
// MessageText:
//
// The size of the manifest exceeds the maximum allowed.
//
#define ERROR_SXS_MANIFEST_TOO_BIG       14105L

//
// MessageId: ERROR_SXS_SETTING_NOT_REGISTERED
//
// MessageText:
//
// The setting is not registered.
//
#define ERROR_SXS_SETTING_NOT_REGISTERED 14106L

//
// MessageId: ERROR_SXS_TRANSACTION_CLOSURE_INCOMPLETE
//
// MessageText:
//
// One or more required members of the transaction are not present.
//
#define ERROR_SXS_TRANSACTION_CLOSURE_INCOMPLETE 14107L

//
// MessageId: ERROR_SMI_PRIMITIVE_INSTALLER_FAILED
//
// MessageText:
//
// The SMI primitive installer failed during setup or servicing.
//
#define ERROR_SMI_PRIMITIVE_INSTALLER_FAILED 14108L

//
// MessageId: ERROR_GENERIC_COMMAND_FAILED
//
// MessageText:
//
// A generic command executable returned a result that indicates failure.
//
#define ERROR_GENERIC_COMMAND_FAILED     14109L

//
// MessageId: ERROR_SXS_FILE_HASH_MISSING
//
// MessageText:
//
// A component is missing file verification information in its manifest.
//
#define ERROR_SXS_FILE_HASH_MISSING      14110L


///////////////////////////////////////////////////
//                                               //
//           End of Side By Side Error Codes     //
//                                               //
//                 14000 to 14999                //
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//                                               //
//           Start of WinEvt Error codes         //
//                                               //
//                 15000 to 15079                //
///////////////////////////////////////////////////

//
// MessageId: ERROR_EVT_INVALID_CHANNEL_PATH
//
// MessageText:
//
// The specified channel path is invalid.
//
#define ERROR_EVT_INVALID_CHANNEL_PATH   15000L

//
// MessageId: ERROR_EVT_INVALID_QUERY
//
// MessageText:
//
// The specified query is invalid.
//
#define ERROR_EVT_INVALID_QUERY          15001L

//
// MessageId: ERROR_EVT_PUBLISHER_METADATA_NOT_FOUND
//
// MessageText:
//
// The publisher metadata cannot be found in the resource.
//
#define ERROR_EVT_PUBLISHER_METADATA_NOT_FOUND 15002L

//
// MessageId: ERROR_EVT_EVENT_TEMPLATE_NOT_FOUND
//
// MessageText:
//
// The template for an event definition cannot be found in the resource (error = %1).
//
#define ERROR_EVT_EVENT_TEMPLATE_NOT_FOUND 15003L

//
// MessageId: ERROR_EVT_INVALID_PUBLISHER_NAME
//
// MessageText:
//
// The specified publisher name is invalid.
//
#define ERROR_EVT_INVALID_PUBLISHER_NAME 15004L

//
// MessageId: ERROR_EVT_INVALID_EVENT_DATA
//
// MessageText:
//
// The event data raised by the publisher is not compatible with the event template definition in the publisher's manifest
//
#define ERROR_EVT_INVALID_EVENT_DATA     15005L

//
// MessageId: ERROR_EVT_CHANNEL_NOT_FOUND
//
// MessageText:
//
// The specified channel could not be found. Check channel configuration.
//
#define ERROR_EVT_CHANNEL_NOT_FOUND      15007L

//
// MessageId: ERROR_EVT_MALFORMED_XML_TEXT
//
// MessageText:
//
// The specified xml text was not well-formed. See Extended Error for more details.
//
#define ERROR_EVT_MALFORMED_XML_TEXT     15008L

//
// MessageId: ERROR_EVT_SUBSCRIPTION_TO_DIRECT_CHANNEL
//
// MessageText:
//
// The caller is trying to subscribe to a direct channel which is not allowed. The events for a direct channel go directly to a logfile and cannot be subscribed to.
//
#define ERROR_EVT_SUBSCRIPTION_TO_DIRECT_CHANNEL 15009L

//
// MessageId: ERROR_EVT_CONFIGURATION_ERROR
//
// MessageText:
//
// Configuration error.
//
#define ERROR_EVT_CONFIGURATION_ERROR    15010L

//
// MessageId: ERROR_EVT_QUERY_RESULT_STALE
//
// MessageText:
//
// The query result is stale / invalid. This may be due to the log being cleared or rolling over after the query result was created. Users should handle this code by releasing the query result object and reissuing the query.
//
#define ERROR_EVT_QUERY_RESULT_STALE     15011L

//
// MessageId: ERROR_EVT_QUERY_RESULT_INVALID_POSITION
//
// MessageText:
//
// Query result is currently at an invalid position.
//
#define ERROR_EVT_QUERY_RESULT_INVALID_POSITION 15012L

//
// MessageId: ERROR_EVT_NON_VALIDATING_MSXML
//
// MessageText:
//
// Registered MSXML doesn't support validation.
//
#define ERROR_EVT_NON_VALIDATING_MSXML   15013L

//
// MessageId: ERROR_EVT_FILTER_ALREADYSCOPED
//
// MessageText:
//
// An expression can only be followed by a change of scope operation if it itself evaluates to a node set and is not already part of some other change of scope operation.
//
#define ERROR_EVT_FILTER_ALREADYSCOPED   15014L

//
// MessageId: ERROR_EVT_FILTER_NOTELTSET
//
// MessageText:
//
// Can't perform a step operation from a term that does not represent an element set.
//
#define ERROR_EVT_FILTER_NOTELTSET       15015L

//
// MessageId: ERROR_EVT_FILTER_INVARG
//
// MessageText:
//
// Left hand side arguments to binary operators must be either attributes, nodes or variables and right hand side arguments must be constants.
//
#define ERROR_EVT_FILTER_INVARG          15016L

//
// MessageId: ERROR_EVT_FILTER_INVTEST
//
// MessageText:
//
// A step operation must involve either a node test or, in the case of a predicate, an algebraic expression against which to test each node in the node set identified by the preceeding node set can be evaluated.
//
#define ERROR_EVT_FILTER_INVTEST         15017L

//
// MessageId: ERROR_EVT_FILTER_INVTYPE
//
// MessageText:
//
// This data type is currently unsupported.
//
#define ERROR_EVT_FILTER_INVTYPE         15018L

//
// MessageId: ERROR_EVT_FILTER_PARSEERR
//
// MessageText:
//
// A syntax error occurred at position %1!d!
//
#define ERROR_EVT_FILTER_PARSEERR        15019L

//
// MessageId: ERROR_EVT_FILTER_UNSUPPORTEDOP
//
// MessageText:
//
// This operator is unsupported by this implementation of the filter.
//
#define ERROR_EVT_FILTER_UNSUPPORTEDOP   15020L

//
// MessageId: ERROR_EVT_FILTER_UNEXPECTEDTOKEN
//
// MessageText:
//
// The token encountered was unexpected.
//
#define ERROR_EVT_FILTER_UNEXPECTEDTOKEN 15021L

//
// MessageId: ERROR_EVT_INVALID_OPERATION_OVER_ENABLED_DIRECT_CHANNEL
//
// MessageText:
//
// The requested operation cannot be performed over an enabled direct channel. The channel must first be disabled before performing the requested operation.
//
#define ERROR_EVT_INVALID_OPERATION_OVER_ENABLED_DIRECT_CHANNEL 15022L

//
// MessageId: ERROR_EVT_INVALID_CHANNEL_PROPERTY_VALUE
//
// MessageText:
//
// Channel property %1!s! contains invalid value. The value has invalid type, is outside of valid range, can't be updated or is not supported by this type of channel.
//
#define ERROR_EVT_INVALID_CHANNEL_PROPERTY_VALUE 15023L

//
// MessageId: ERROR_EVT_INVALID_PUBLISHER_PROPERTY_VALUE
//
// MessageText:
//
// Publisher property %1!s! contains invalid value. The value has invalid type, is outside of valid range, can't be updated or is not supported by this type of publisher.
//
#define ERROR_EVT_INVALID_PUBLISHER_PROPERTY_VALUE 15024L

//
// MessageId: ERROR_EVT_CHANNEL_CANNOT_ACTIVATE
//
// MessageText:
//
// The channel fails to activate.
//
#define ERROR_EVT_CHANNEL_CANNOT_ACTIVATE 15025L

//
// MessageId: ERROR_EVT_FILTER_TOO_COMPLEX
//
// MessageText:
//
// The xpath expression exceeded supported complexity. Please symplify it or split it into two or more simple expressions.
//
#define ERROR_EVT_FILTER_TOO_COMPLEX     15026L

//
// MessageId: ERROR_EVT_MESSAGE_NOT_FOUND
//
// MessageText:
//
// the message resource is present but the message is not found in the string/message table
//
#define ERROR_EVT_MESSAGE_NOT_FOUND      15027L

//
// MessageId: ERROR_EVT_MESSAGE_ID_NOT_FOUND
//
// MessageText:
//
// The message id for the desired message could not be found.
//
#define ERROR_EVT_MESSAGE_ID_NOT_FOUND   15028L

//
// MessageId: ERROR_EVT_UNRESOLVED_VALUE_INSERT
//
// MessageText:
//
// The substitution string for insert index (%1) could not be found.
//
#define ERROR_EVT_UNRESOLVED_VALUE_INSERT 15029L

//
// MessageId: ERROR_EVT_UNRESOLVED_PARAMETER_INSERT
//
// MessageText:
//
// The description string for parameter reference (%1) could not be found.
//
#define ERROR_EVT_UNRESOLVED_PARAMETER_INSERT 15030L

//
// MessageId: ERROR_EVT_MAX_INSERTS_REACHED
//
// MessageText:
//
// The maximum number of replacements has been reached.
//
#define ERROR_EVT_MAX_INSERTS_REACHED    15031L

//
// MessageId: ERROR_EVT_EVENT_DEFINITION_NOT_FOUND
//
// MessageText:
//
// The event definition could not be found for event id (%1).
//
#define ERROR_EVT_EVENT_DEFINITION_NOT_FOUND 15032L

//
// MessageId: ERROR_EVT_MESSAGE_LOCALE_NOT_FOUND
//
// MessageText:
//
// The locale specific resource for the desired message is not present.
//
#define ERROR_EVT_MESSAGE_LOCALE_NOT_FOUND 15033L

//
// MessageId: ERROR_EVT_VERSION_TOO_OLD
//
// MessageText:
//
// The resource is too old to be compatible.
//
#define ERROR_EVT_VERSION_TOO_OLD        15034L

//
// MessageId: ERROR_EVT_VERSION_TOO_NEW
//
// MessageText:
//
// The resource is too new to be compatible.
//
#define ERROR_EVT_VERSION_TOO_NEW        15035L

//
// MessageId: ERROR_EVT_CANNOT_OPEN_CHANNEL_OF_QUERY
//
// MessageText:
//
// The channel at index %1!d! of the query can't be opened.
//
#define ERROR_EVT_CANNOT_OPEN_CHANNEL_OF_QUERY 15036L

//
// MessageId: ERROR_EVT_PUBLISHER_DISABLED
//
// MessageText:
//
// The publisher has been disabled and its resource is not avaiable.  This
// usually occurs when the publisher is in the process of being uninstalled
// or upgraded.
//
#define ERROR_EVT_PUBLISHER_DISABLED     15037L

//
// MessageId: ERROR_EVT_FILTER_OUT_OF_RANGE
//
// MessageText:
//
// Attempted to create a numeric type that is outside of its valid range.
//
#define ERROR_EVT_FILTER_OUT_OF_RANGE    15038L


///////////////////////////////////////////////////
//                                               //
//           Start of Wecsvc Error codes         //
//                                               //
//                 15080 to 15099                //
///////////////////////////////////////////////////

//
// MessageId: ERROR_EC_SUBSCRIPTION_CANNOT_ACTIVATE
//
// MessageText:
//
// The subscription fails to activate.
//
#define ERROR_EC_SUBSCRIPTION_CANNOT_ACTIVATE 15080L

//
// MessageId: ERROR_EC_LOG_DISABLED
//
// MessageText:
//
// The log of the subscription is in disabled state, and can not be used to forward events to. The log must first be enabled before the subscription can be activated.
//
#define ERROR_EC_LOG_DISABLED            15081L

//
// MessageId: ERROR_EC_CIRCULAR_FORWARDING
//
// MessageText:
//
// When forwarding events from local machine to itself, the query of the subscription can't contain target log of the subscription.
//
#define ERROR_EC_CIRCULAR_FORWARDING     15082L

//
// MessageId: ERROR_EC_CREDSTORE_FULL
//
// MessageText:
//
// The credential store that is used to save credentials is full.
//
#define ERROR_EC_CREDSTORE_FULL          15083L

//
// MessageId: ERROR_EC_CRED_NOT_FOUND
//
// MessageText:
//
// The credential used by this subscription can't be found in credential store.
//
#define ERROR_EC_CRED_NOT_FOUND          15084L

//
// MessageId: ERROR_EC_NO_ACTIVE_CHANNEL
//
// MessageText:
//
// No active channel is found for the query.
//
#define ERROR_EC_NO_ACTIVE_CHANNEL       15085L


///////////////////////////////////////////////////
//                                               //
//           Start of MUI Error codes            //
//                                               //
//                 15100 to 15199                //
///////////////////////////////////////////////////

//
// MessageId: ERROR_MUI_FILE_NOT_FOUND
//
// MessageText:
//
// The resource loader failed to find MUI file.
//
#define ERROR_MUI_FILE_NOT_FOUND         15100L    

//
// MessageId: ERROR_MUI_INVALID_FILE
//
// MessageText:
//
// The resource loader failed to load MUI file because the file fail to pass validation.
//
#define ERROR_MUI_INVALID_FILE           15101L    

//
// MessageId: ERROR_MUI_INVALID_RC_CONFIG
//
// MessageText:
//
// The RC Manifest is corrupted with garbage data or unsupported version or missing required item.
//
#define ERROR_MUI_INVALID_RC_CONFIG      15102L    

//
// MessageId: ERROR_MUI_INVALID_LOCALE_NAME
//
// MessageText:
//
// The RC Manifest has invalid culture name.
//
#define ERROR_MUI_INVALID_LOCALE_NAME    15103L    

//
// MessageId: ERROR_MUI_INVALID_ULTIMATEFALLBACK_NAME
//
// MessageText:
//
// The RC Manifest has invalid ultimatefallback name.
//
#define ERROR_MUI_INVALID_ULTIMATEFALLBACK_NAME 15104L    

//
// MessageId: ERROR_MUI_FILE_NOT_LOADED
//
// MessageText:
//
// The resource loader cache doesn't have loaded MUI entry.
//
#define ERROR_MUI_FILE_NOT_LOADED        15105L    

//
// MessageId: ERROR_RESOURCE_ENUM_USER_STOP
//
// MessageText:
//
// User stopped resource enumeration.
//
#define ERROR_RESOURCE_ENUM_USER_STOP    15106L

//
// MessageId: ERROR_MUI_INTLSETTINGS_UILANG_NOT_INSTALLED
//
// MessageText:
//
// UI language installation failed.
//
#define ERROR_MUI_INTLSETTINGS_UILANG_NOT_INSTALLED 15107L

//
// MessageId: ERROR_MUI_INTLSETTINGS_INVALID_LOCALE_NAME
//
// MessageText:
//
// Locale installation failed.
//
#define ERROR_MUI_INTLSETTINGS_INVALID_LOCALE_NAME 15108L


///////////////////////////////////////////////////
//                                               //
// Start of Monitor Configuration API error codes//
//                                               //
//                 15200 to 15249                //
///////////////////////////////////////////////////

//
// MessageId: ERROR_MCA_INVALID_CAPABILITIES_STRING
//
// MessageText:
//
// The monitor returned a DDC/CI capabilities string that did not comply with the ACCESS.bus 3.0, DDC/CI 1.1 or MCCS 2 Revision 1 specification.
//
#define ERROR_MCA_INVALID_CAPABILITIES_STRING 15200L

//
// MessageId: ERROR_MCA_INVALID_VCP_VERSION
//
// MessageText:
//
// The monitor's VCP Version (0xDF) VCP code returned an invalid version value.
//
#define ERROR_MCA_INVALID_VCP_VERSION    15201L

//
// MessageId: ERROR_MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION
//
// MessageText:
//
// The monitor does not comply with the MCCS specification it claims to support.
//
#define ERROR_MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION 15202L

//
// MessageId: ERROR_MCA_MCCS_VERSION_MISMATCH
//
// MessageText:
//
// The MCCS version in a monitor's mccs_ver capability does not match the MCCS version the monitor reports when the VCP Version (0xDF) VCP code is used.
//
#define ERROR_MCA_MCCS_VERSION_MISMATCH  15203L

//
// MessageId: ERROR_MCA_UNSUPPORTED_MCCS_VERSION
//
// MessageText:
//
// The Monitor Configuration API only works with monitors that support the MCCS 1.0 specification, MCCS 2.0 specification or the MCCS 2.0 Revision 1 specification.
//
#define ERROR_MCA_UNSUPPORTED_MCCS_VERSION 15204L

//
// MessageId: ERROR_MCA_INTERNAL_ERROR
//
// MessageText:
//
// An internal Monitor Configuration API error occurred.
//
#define ERROR_MCA_INTERNAL_ERROR         15205L

//
// MessageId: ERROR_MCA_INVALID_TECHNOLOGY_TYPE_RETURNED
//
// MessageText:
//
// The monitor returned an invalid monitor technology type. CRT, Plasma and LCD (TFT) are examples of monitor technology types. This error implies that the monitor violated the MCCS 2.0 or MCCS 2.0 Revision 1 specification.
//
#define ERROR_MCA_INVALID_TECHNOLOGY_TYPE_RETURNED 15206L

//
// MessageId: ERROR_MCA_UNSUPPORTED_COLOR_TEMPERATURE
//
// MessageText:
//
// The caller of SetMonitorColorTemperature specified a color temperature that the current monitor did not support. This error implies that the monitor violated the MCCS 2.0 or MCCS 2.0 Revision 1 specification.
//
#define ERROR_MCA_UNSUPPORTED_COLOR_TEMPERATURE 15207L


//////////////////////////////////////////////////
//                                              //
// End of Monitor Configuration API error codes //
//                                              //
//                15200 to 15249                //
//                                              //
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//                                              //
//         Start of Syspart error codes         //
//                15250 - 15299                 //
//                                              //
//////////////////////////////////////////////////

//
// MessageId: ERROR_AMBIGUOUS_SYSTEM_DEVICE
//
// MessageText:
//
// The requested system device cannot be identified due to multiple indistinguishable devices potentially matching the identification criteria.
//
#define ERROR_AMBIGUOUS_SYSTEM_DEVICE    15250L

//
// MessageId: ERROR_SYSTEM_DEVICE_NOT_FOUND
//
// MessageText:
//
// The requested system device cannot be found.
//
#define ERROR_SYSTEM_DEVICE_NOT_FOUND    15299L

