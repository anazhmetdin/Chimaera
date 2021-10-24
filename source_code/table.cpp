#include "table.h"
#include "hash_f.h"
#include <fstream>
#include <iostream>

using namespace std;

table::table()
{
  // this is the constructor function

  // the size of the table is determined by hash_f
  size = MAX_HASH_VALUE;
  // array of linked lists to store suplementary reads
  sup_reads = new linked *[size];
}

void table::hashF(read r_instance)
{
  // this is the hashing function
  // it takes as an input a read object

  // extract the Qname of the read object and its length
  string Qname_str = r_instance.getQname();
  const char *Qname = Qname_str.c_str();
  int Qlen = strlen(Qname);
  // get the index based on the Qname
  int ind = Perfect_Hash::hash(Qname, Qlen);
  // if it's the first opject in the row, create new list with this read as the head
  if (sup_reads[ind] == nullptr)
  {
    sup_reads[ind] = new linked(r_instance);
  }
  else
  {
    // if it's NOT the first opject in the row, add it to the list
    sup_reads[ind]->addToTail(r_instance);
  }

  return;
}

bool table::found_matched(Node *first, Node *second)
{
  // This function check if two reads are matched in a loci pair before

  if (loci.empty())
  {
    return false;
  }

  // loci pairs are stored in a dynamic array of lists
  // odd indexed reads in the list is matched to the first refrence
  // even indexed reads in the list is matched to the second refrence

  // two pointers to read pairs of in each loci
  Node *searching_back;
  Node *searching_front;
  // loop over each loci pair matched
  for (int i = 0; i < loci.size(); i++)
  {
    // start from the first two pairs in the loci
    searching_back = loci[i].supporting_reads->head;
    searching_front = searching_back->next;
    // loop over each two possible pairs in the loci
    // and check if the two pointers point to the same reads as the input
    while (searching_front != NULL)
    {
      if (searching_back == first)
      {
        if (searching_front == second)
        {
          return true;
        }
      }
      if (searching_front == first)
      {
        if (searching_back == second)
        {
          return true;
        }
        if (searching_front->next == second)
        {
          return true;
        }
      }
      searching_back = searching_back->next;
      searching_front = searching_front->next;
    }
  }
  return false;
}

void table::check_support()
{
  // this function parse all stored reads to match each two reads in one row
  // to all possible pairs in the following rows

  // two pointers to start the base of a new loci pair
  Node *first;
  Node *second;
  // locus opject that store the distinctive info of a loci pair and the supporting reads
  locus *match;
  // ask the user the enter the maximum number of adjacency pairs
  int maximum_limit;
  cout << "what is the maximim limit of distance between reads? ";
  cin >> maximum_limit;
  // loop over all rows of the table
  for (int i = 0; i < size - 1; i++)
  {
    // if the index is empty check the next index
    if (sup_reads[i] == nullptr)
    {
      continue;
    }
    // if it's not empty, set the first read in row as the first locus base in a locus pair
    first = sup_reads[i]->head;
    // loop over the rest in the same row as first
    while (first != sup_reads[i]->tail)
    {
      //  second start from the next read after the first
      second = first->next;
      // second loop over the rest of reads in the same row
      while (second != NULL)
      {
        // if first and second are marked as paired, check the next second
        if (first->data.getPos() == second->data.getPnext() || second->data.getPos() == first->data.getPnext())
        {
          second = second->next;
          continue;
        }
        // if first and second are matched before, check the next second
        else if (found_matched(first, second))
        {
          second = second->next;
          continue;
        }
        // add first and second as the bases of a new loci pair
        match = new locus(first, second);
        // loop over the following rows
        for (int j = i + 1; j < size; j++)
        {
          match = new locus(first, second);
          // if the index is empty check the next index
          if (sup_reads[j] == nullptr)
          {
            continue;
          }
          // pointer to a read, to loop over the each read in the row
          Node *temp = sup_reads[j]->head;
          // pointer to point to the read that matched the first base in pairs
          Node *match_first = nullptr;
          // pointer to point to the read that matched the second base in pairs
          Node *match_second = nullptr;
          // loop over the rest of the reads in the line
          while (temp != NULL)
          {
            // match with the first if temp and first have the same refrence and direction
            if (temp->data.getRname() == match->first_Rname && match_first == nullptr && temp->data.getDir() == match->first_dir)
            {
              // match with the first if temp and first have convenient adjacency
              if (temp->data.getPos() <= match->first_end + maximum_limit && temp->data.getPos() + temp->data.getLen() >= match->first_start)
              {
                match_first = temp;
                match->first_start = min(temp->data.getPos(), match->first_start);
                match->first_end = max(temp->data.getPos() + temp->data.getLen(), match->first_end);
                temp = temp->next;
                continue;
              }
              else if (temp->data.getPos() + temp->data.getLen() >= match->first_start - maximum_limit && temp->data.getPos() + temp->data.getLen() <= match->first_start)
              {
                match_first = temp;
                match->first_start = min(temp->data.getPos(), match->first_start);
                match->first_end = max(temp->data.getPos() + temp->data.getLen(), match->first_end);
                temp = temp->next;
                continue;
              }
            }
            // match with the second if temp and second have the same refrence and direction
            else if (temp->data.getRname() == match->second_Rname && match_second == nullptr && temp->data.getDir() == match->second_dir)
            {
              // match with the second if temp and second have convenient adjacency
              if (temp->data.getPos() <= match->second_end + maximum_limit && temp->data.getPos() + temp->data.getLen() >= match->second_start)
              {
                match_second = temp;
                //expand the range of the locus
                match->second_start = min(temp->data.getPos(), match->second_start);
                match->second_end = max(temp->data.getPos() + temp->data.getLen(), match->second_end);
                temp = temp->next;
                continue;
              }
              else if (temp->data.getPos() + temp->data.getLen() >= match->second_start - maximum_limit && temp->data.getPos() + temp->data.getLen() <= match->second_start)
              {
                match_second = temp;
                match->second_start = min(temp->data.getPos(), match->second_start);
                match->second_end = max(temp->data.getPos() + temp->data.getLen(), match->second_end);
                temp = temp->next;
                continue;
              }
            }
            // check the first read in row
            temp = temp->next;
          }
          // if first and second are matched, add to the loci
          if (match_first != nullptr && match_second != nullptr)
          {
            match->supporting_reads->addToTail(match_first->data);
            match->supporting_reads->addToTail(match_second->data);
          }
        }
        // after finishing the following rows
        // add all matched to the array of loci
        loci.push_back(*match);
        second = second->next;
      }
      first = first->next;
    }
  }
}

void table::report_support()
{
  // this function is to generate a file of all loci pairs

  if (loci.empty())
  {
    return;
  }
  // node pointer to the read being reported
  Node *reporting;
  // two read objects to store the odd and even supporting reads in each loci pair
  read first_read;
  read second_read;
  // variables to store info for each loci being reported
  int first_start_range;
  int first_end_range;
  int second_start_range;
  int second_end_range;
  int num_supp_reads;
  // ask the user to input minimum_limit of supporting_reads to be reported
  int minimum_limit;
  cout << "what is the minimum number of supporting reads? ";
  cin >> minimum_limit;

  // create object to stream data to be append to a file
  ofstream report("./pipline_run/supported_loci.txt", ios::app);

  if (report.is_open())
  {

    //loop over each loci pair
    for (int i = 0; i < loci.size(); i++)
    {
      // start reporting at the first odd read
      reporting = loci[i].supporting_reads->head;

      first_read = reporting->data;

      first_start_range = reporting->data.getPos();
      first_end_range = first_start_range + reporting->data.getLen();

      reporting = reporting->next;

      second_read = reporting->data;

      second_start_range = reporting->data.getPos();
      second_end_range = first_start_range + reporting->data.getLen();

      string supporting_lines = "";
      supporting_lines = supporting_lines + ">>" + first_read.getRname() + "\t" + to_string(first_read.getDir()) + "\n";
      supporting_lines = supporting_lines + ">>" + second_read.getRname() + "\t" + to_string(second_read.getDir()) + "\n";
      supporting_lines = supporting_lines + first_read.printRead();
      supporting_lines = supporting_lines + second_read.printRead();

      num_supp_reads = 1;

      reporting = reporting->next;
      // loop over the rest odd and even in supporting reads
      while (reporting != NULL)
      {
        first_start_range = min(reporting->data.getPos(), first_start_range);
        first_end_range = max(reporting->data.getPos() + reporting->data.getLen(), first_end_range);

        supporting_lines = supporting_lines + reporting->data.printRead();
        reporting = reporting->next;

        second_start_range = min(reporting->data.getPos(), second_start_range);
        second_end_range = max(reporting->data.getPos() + reporting->data.getLen(), second_end_range);

        supporting_lines = supporting_lines + reporting->data.printRead();
        reporting = reporting->next;

        num_supp_reads++;
      }
      if (num_supp_reads >= minimum_limit)
      {
        report << "@" << num_supp_reads << "\t" << first_start_range << "-" << first_end_range << "\t" << second_start_range << "-" << second_end_range << "\n";
        report << supporting_lines;
      }
    }
    report.close();
  }
  return;
}
