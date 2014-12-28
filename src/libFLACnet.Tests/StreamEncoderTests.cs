namespace FLAC
{
    using System;
    using System.Collections.Generic;
    using System.IO;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;

    using Microsoft.VisualStudio.TestTools.UnitTesting;

    [TestClass]
    public class StreamEncoderTests
    {
        [TestMethod]
        public void Construction_IsValid()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());

            Assert.IsTrue(encoder.IsValid);
        }

        [TestMethod]
        public void Initialize()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.Initialize();
        }

        [TestMethod]
        public void SetOggSerialNumber()
        {
            int serial = 12345;

            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.SetOggSerialNumber(serial);
        }

        [TestMethod]
        public void Verify_SetTrue()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.Verify = true;
        }

        [TestMethod]
        public void Verify_SetTrueInitialized()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.Verify = true;
            encoder.Initialize();

            Assert.IsTrue(encoder.Verify);
        }

        [TestMethod]
        public void Verify_SetFalse()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.Verify = false;
        }

        [TestMethod]
        public void StreamableSubet_SetTrue()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.StreamableSubset = true;
        }

        [TestMethod]
        public void StreamableSubet_SetFalse()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.StreamableSubset = false;
        }

        [TestMethod]
        public void Channels_SetOne()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.Channels = 1;
        }

        [TestMethod]
        public void Channels_SetTwo()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.Channels = 2;
        }

        [TestMethod]
        public void BitsPerSample_SetEight()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.BitsPerSample = 8;
        }

        [TestMethod]
        public void BitsPerSample_SetSixteen()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.BitsPerSample = 16;
        }

        [TestMethod]
        public void SampleRate_Set44100()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.SampleRate = 44100;
        }

        [TestMethod]
        public void SampleRate_Set39012()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.SampleRate = 39012;
        }

        [TestMethod]
        public void SetCompressionLevel_SetZero()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.SetCompressionLevel(0);
        }

        [TestMethod]
        public void SetCompressionLevel_SetMaximum()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.SetCompressionLevel(uint.MaxValue);
        }

        [TestMethod]
        public void BlockSize_Set576()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.BlockSize = 576;
        }

        [TestMethod]
        public void BlockSize_Set0()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.BlockSize = 0;
        }

        [TestMethod]
        public void MidSideStereo_SetFalse()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.MidSideStereo = false;
        }

        [TestMethod]
        public void MidSideStereo_SetTrue()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.MidSideStereo = true;
        }

        [TestMethod]
        public void LooseMidSideStereo_SetTrue()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.LooseMidSideStereo = true;
        }

        [TestMethod]
        public void LooseMidSideStereo_SetFalse()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.LooseMidSideStereo = false;
        }

        [TestMethod]
        public void MaxLpcOrder_SetZero()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.MaxLpcOrder = 0;
        }

        [TestMethod]
        public void MaxLpcOrder_SetMaxValue()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.MaxLpcOrder = uint.MaxValue;
        }

        [TestMethod]
        public void QlpCoeffPrecision_SetZero()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.QlpCoeffPrecision = 0;
        }

        [TestMethod]
        public void QlpCoeffPrecision_SetMaxValue()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.QlpCoeffPrecision = uint.MaxValue;
        }

        [TestMethod]
        public void QlpCoeffPrecisionSearch_SetFalse()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.QlpCoeffPrecisionSearch = false;
        }

        [TestMethod]
        public void QlpCoeffPrecisionSearch_SetTrue()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.QlpCoeffPrecisionSearch = true;
        }

        [TestMethod]
        public void EscapeCoding_SetFalse()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.EscapeCoding = false;
        }

        [TestMethod]
        public void EscapeCoding_SetTrue()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.EscapeCoding = true;
        }

        [TestMethod]
        public void ExhaustiveModelSearch_SetFalse()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.ExhaustiveModelSearch = false;
        }

        [TestMethod]
        public void ExhaustiveModelSearch_SetTrue()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.ExhaustiveModelSearch = true;
        }

        [TestMethod]
        public void ResidualPartitionOrderMinimum_SetZero()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.ResidualPartitionOrderMinimum = 0;
        }

        [TestMethod]
        public void ResidualPartitionOrderMinimum_SetMaxValue()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.ResidualPartitionOrderMinimum = uint.MaxValue;
        }

        [TestMethod]
        public void ResidualPartitionOrderMaximum_SetZero()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.ResidualPartitionOrderMaximum = 0;
        }

        [TestMethod]
        public void ResidualPartitionOrderMaximum_SetMaxValue()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.ResidualPartitionOrderMaximum = uint.MaxValue;
        }

        [TestMethod]
        public void TotalSamplesEstimate_SetZero()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.TotalSamplesEstimate = 0;
        }

        [TestMethod]
        public void TotalSamplesEstimate_SetMaxValue()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.TotalSamplesEstimate = ulong.MaxValue;
        }

        [TestMethod]
        public void GetState_IsNotNull()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            EncoderStreamState state = encoder.GetState();

            Assert.IsNotNull(state);
        }

        [TestMethod]
        public void GetState_Initialized_IsNotNull()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.Initialize();

            EncoderStreamState state = encoder.GetState();

            Assert.IsNotNull(state);
        }

        [TestMethod]
        public void GetVerifyStreamState_IsNotNull()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            DecoderStreamState verifyState = encoder.GetVerifyStreamState();

            Assert.IsNotNull(verifyState);
        }

        [TestMethod]
        public void GetVerifyStreamState_Initialized_IsNotNull()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.Initialize();

            DecoderStreamState verifyState = encoder.GetVerifyStreamState();

            Assert.IsNotNull(verifyState);
        }

        [TestMethod]
        public void GetDecoderErrors_IsNotNull()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            DecoderErrorStats stats = encoder.GetDecoderErrorStats();

            Assert.IsNotNull(stats);
        }

        [TestMethod]
        public void GetDecoderErrors_Intialized_IsNotNull()
        {
            StreamEncoder encoder = new StreamEncoder(new MemoryStream());
            encoder.Initialize();

            DecoderErrorStats stats = encoder.GetDecoderErrorStats();

            Assert.IsNotNull(stats);
        }

        [TestMethod]
        public void Initialize_AsFlac()
        {
            uint channels = 1;
            uint bitsPerSample = 8;
            uint sampleRate = 44100;
            uint blockSize = 576;
            uint maxLpcOrder = 0;
            uint autoQlpCoeffPrecision = 0;
            uint expectedQlpCoeffPrecision = 6;
            uint residualPartitionOrderMaximum = 0;
            uint residualPartitionOrderMinimum = 0;
            uint totalSamplesEstimate = 0;

            System.IO.MemoryStream stream = new System.IO.MemoryStream();
            StreamEncoder encoder = new StreamEncoder(stream);

            encoder.Verify = true;
            encoder.StreamableSubset = true;
            encoder.Channels = channels;
            encoder.BitsPerSample = bitsPerSample;
            encoder.SampleRate = sampleRate;
            encoder.SetCompressionLevel(uint.MaxValue);
            encoder.BlockSize = blockSize;
            encoder.MidSideStereo = false;
            encoder.LooseMidSideStereo = false;
            encoder.MaxLpcOrder = maxLpcOrder;
            encoder.QlpCoeffPrecision = autoQlpCoeffPrecision;
            encoder.QlpCoeffPrecisionSearch = false;
            encoder.EscapeCoding = false;
            encoder.ExhaustiveModelSearch = false;
            encoder.ResidualPartitionOrderMinimum = residualPartitionOrderMinimum;
            encoder.ResidualPartitionOrderMaximum = residualPartitionOrderMaximum;
            encoder.TotalSamplesEstimate = totalSamplesEstimate;
            encoder.Initialize();

            Assert.IsNotNull(encoder.GetState());
            Assert.IsNotNull(encoder.GetVerifyStreamState());
            Assert.IsNotNull(encoder.GetDecoderErrorStats());

            Assert.IsTrue(encoder.Verify);
            Assert.IsTrue(encoder.StreamableSubset);
            Assert.IsFalse(encoder.MidSideStereo);
            Assert.IsFalse(encoder.LooseMidSideStereo);
            Assert.AreEqual(encoder.Channels, channels);
            Assert.AreEqual(encoder.BitsPerSample, bitsPerSample);
            Assert.AreEqual(encoder.SampleRate, sampleRate);
            Assert.AreEqual(encoder.BlockSize, blockSize);
            Assert.AreEqual(encoder.MaxLpcOrder, maxLpcOrder);
            Assert.AreEqual(encoder.QlpCoeffPrecision, expectedQlpCoeffPrecision);
            Assert.IsFalse(encoder.QlpCoeffPrecisionSearch);
            Assert.IsFalse(encoder.EscapeCoding);
            Assert.IsFalse(encoder.ExhaustiveModelSearch);
            Assert.AreEqual(encoder.ResidualPartitionOrderMinimum, residualPartitionOrderMinimum);
            Assert.AreEqual(encoder.ResidualPartitionOrderMaximum, residualPartitionOrderMaximum);
            Assert.AreEqual(encoder.TotalSamplesEstimate, totalSamplesEstimate);

            int[] samples = new int[1024];
            for (int i = 0; i < samples.Length; i++)
            {
                samples[i] = i & 7;
            }

            encoder.Process(new[] { samples }, (uint)samples.Length);
            encoder.ProcessInterleaved(samples, (uint)samples.Length);

            try
            {
                encoder.Finish();
            }
            catch (Exception)
            {
                var state = encoder.GetState();
                throw;
            }
        }

        [TestMethod]
        public void Initialize_AsOgg()
        {
            uint channels = 1;
            uint bitsPerSample = 8;
            uint sampleRate = 44100;
            uint blockSize = 576;
            uint maxLpcOrder = 0;
            uint autoQlpCoeffPrecision = 0;
            uint expectedQlpCoeffPrecision = 6;
            uint residualPartitionOrderMaximum = 0;
            uint residualPartitionOrderMinimum = 0;
            uint totalSamplesEstimate = 0;

            System.IO.MemoryStream stream = new System.IO.MemoryStream();
            StreamEncoder encoder = new StreamEncoder(stream);

            encoder.Verify = true;
            encoder.StreamableSubset = true;
            encoder.Channels = channels;
            encoder.BitsPerSample = bitsPerSample;
            encoder.SampleRate = sampleRate;
            encoder.SetCompressionLevel(uint.MaxValue);
            encoder.BlockSize = blockSize;
            encoder.MidSideStereo = false;
            encoder.LooseMidSideStereo = false;
            encoder.MaxLpcOrder = maxLpcOrder;
            encoder.QlpCoeffPrecision = autoQlpCoeffPrecision;
            encoder.QlpCoeffPrecisionSearch = false;
            encoder.EscapeCoding = false;
            encoder.ExhaustiveModelSearch = false;
            encoder.ResidualPartitionOrderMinimum = residualPartitionOrderMinimum;
            encoder.ResidualPartitionOrderMaximum = residualPartitionOrderMaximum;
            encoder.TotalSamplesEstimate = totalSamplesEstimate;
            encoder.InitializeOgg();

            Assert.IsNotNull(encoder.GetState());
            Assert.IsNotNull(encoder.GetVerifyStreamState());
            Assert.IsNotNull(encoder.GetDecoderErrorStats());

            Assert.IsTrue(encoder.Verify);
            Assert.IsTrue(encoder.StreamableSubset);
            Assert.IsFalse(encoder.MidSideStereo);
            Assert.IsFalse(encoder.LooseMidSideStereo);
            Assert.AreEqual(encoder.Channels, channels);
            Assert.AreEqual(encoder.BitsPerSample, bitsPerSample);
            Assert.AreEqual(encoder.SampleRate, sampleRate);
            Assert.AreEqual(encoder.BlockSize, blockSize);
            Assert.AreEqual(encoder.MaxLpcOrder, maxLpcOrder);
            Assert.AreEqual(encoder.QlpCoeffPrecision, expectedQlpCoeffPrecision);
            Assert.IsFalse(encoder.QlpCoeffPrecisionSearch);
            Assert.IsFalse(encoder.EscapeCoding);
            Assert.IsFalse(encoder.ExhaustiveModelSearch);
            Assert.AreEqual(encoder.ResidualPartitionOrderMinimum, residualPartitionOrderMinimum);
            Assert.AreEqual(encoder.ResidualPartitionOrderMaximum, residualPartitionOrderMaximum);
            Assert.AreEqual(encoder.TotalSamplesEstimate, totalSamplesEstimate);

            int[] samples = new int[1024];
            for (int i = 0; i < samples.Length; i++)
            {
                samples[i] = i & 7;
            }

            encoder.Process(new[] { samples }, (uint)samples.Length);
            encoder.ProcessInterleaved(samples, (uint)samples.Length);

            try
            {
                encoder.Finish();
            }
            catch (Exception)
            {
                var state = encoder.GetState();
                throw;
            }
        }
    }
}
