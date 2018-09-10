#pragma once
#include "IManager.h"
#include "HashTableAsync.h"
#include <thread>

/**
 * Class handles async block hashing
 * One seeding block - one processing thread
 * Manager set data to output only when all threads will be finished
 */
class ThreadManager : public IManager
{
public:

  /**
   * Manager constructor
   * Number of threads should be limited in order to\n
   * not overflow the memory on large files
   * @param limit - maximum allocated threads
   */
  explicit ThreadManager(size_t limit);

  virtual ~ThreadManager() = default;

  /**
   * Method processing block
   * Creates thread which calculate hash
   * If incoming block exceeds threads limit,\n
   * called thread will be blocked till threads are done
   * @param block - data bytes
   * @param size - data size
   */
  virtual void Seed(const std::vector<char>& block, long int size) override;

  /**
   * Set output
   * @param file - which obtain result hashes
   */
  virtual void SetOutput(File&& file) override;

  /**
   * Write seeded and processed data to output
   */
  virtual void Write() override;

  /**
   * Block called thread and \n
   * write all pending data to output
   * Then clean all resources
   */
  virtual void Clear() override;

  const size_t limit;

protected:

  /**
   * Update outputs
   */
  void Update();

  /**
   * Output table which store preliminary hashes
   */
  HashTableAsync table;

  /**
   * File with result data
   */
  File output;

private:

  void Wait();

  void CleanThreads();

  std::vector<std::thread> threads;

  int id;
};
