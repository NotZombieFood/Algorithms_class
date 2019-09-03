Semaphore *make_semaphore(int value)
{
  Semaphore *sem = check_malloc(sizeof(Semaphore));
  int n = sem_init(sem, 0, value);
  if (n != 0) perror_exit("sem_init failed");
  return sem;
}