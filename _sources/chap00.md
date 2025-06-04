# Chapter 0: Setup

The software tools used to execute the examples introduced in this session, as well as the exercises assigned will be are packaged within a CMSSW enviornment in the LPC cluster, and a local compiler. Use whichever one is most convenient for you to use. If, however, you find that neither of these work for you in time for the session, as a last resort, you can also use the [C++ Shell](https://cpp.sh/) website. This options has its limitations in that it cannot make use of user made header files, but it will suffice for most of the material presented.

## The LPC Cluster

Add the following to your *local* `~/.ssh/config` file

```{code}
Host cmslpc-*.fnal.gov
  StrictHostKeyChecking no
  UserKnownHostsFile /dev/null
```

and log into the LPC cluster. Once you have logged in, run the following commands

```{code}
mkdir nobackup/PURSUE-CPP
cd nobackup/PURSUE-CPP
source /cvmfs/cms.cern.ch/cmsset_default.sh
cmsrel CMSSW_15_0_0
cd CMSSW_15_0_0/src/
cmsenv
git clone https://github.com/athete/pursue-cpp-workshop
cd pursue-cpp-workshop
```

To test that you have the right environment installed, complie and run `helloworld.cpp`

```{code}
cd examples_cpp
g++ -o helloworld helloworld.cpp
./helloworld
```
You should see the following output

```
Hello, World!
```

## Local

If you instead choose to run the examples locally, your machine should already have a C++ compiler packaged with the operating system. To make sure that this is the case, run ```g++ --version```. This prints the version of the C++ compiler installed on your computer, if you get any other output complaining about the command not being found, run the following to install it

```{code}
sudo yum install gcc-c++
```

Next, clone this repository
```{code}
git clone https://github.com/athete/pursue-cpp-workshop
cd pursue-cpp-workshop
```

And test that everything is running as expected by compiling and running `helloworld.cpp`

```{code}
cd examples
g++ -o helloworld helloworld.cpp
./helloworld
```

You should see the following output

```
Hello, World!
```
