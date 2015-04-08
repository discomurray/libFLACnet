using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FLAC
{
    using Microsoft.VisualStudio.TestTools.UnitTesting;

    enum Layer
    {
        Stream,
        SeekableStream,
        File,
        FileName,
    }

    [TestClass]
    public class EncoderTests
    {
        private StreamInfo streamInfo;

        private Padding padding;

        private SeekTable seekTable;

        private Application application1;

        private Application application2;

        private VorbisComment vorbisComment;

        private CueSheet cueSheet;

        private Picture picture;

        private CustomMetadata unknown;

        [TestMethod]
        public void Encoder()
        {
            bool isOgg = false;

            while (true)
            {
                this.InitializeMetadataBlocks();

                this.StreamEncoder(Layer.Stream, isOgg);

                this.StreamEncoder(Layer.SeekableStream, isOgg);

                this.StreamEncoder(Layer.File, isOgg);

                this.StreamEncoder(Layer.FileName, isOgg);

                this.RemoveFile(this.FlacFileName(isOgg));

                this.FreeMetadataBlocks();

                if (!Ogg.IsSupported || isOgg)
                {
                    break;
                }

                isOgg = true;
            }
        }

        private void FreeMetadataBlocks()
        {
            throw new NotImplementedException();
        }

        private void RemoveFile(string flacFileName)
        {
            throw new NotImplementedException();
        }

        private string FlacFileName(bool isOgg)
        {
            throw new NotImplementedException();
        }

        private void StreamEncoder(Layer layer, bool isOgg)
        {
            throw new NotImplementedException();
        }

        private void InitializeMetadataBlocks()
        {
            this.streamInfo = new StreamInfo()
            {
                MinBlockSize = 576,
                MaxBlockSize = 576,
                MinFrameSize = 0,
                MaxFrameSize = 0,
                SampleRate = 44100,
                Channels = 1,
                BitsPerSample = 8,
                TotalSamples = 0,
            };

            this.padding = new Padding()
            {
                Length = 1234,
            };

            this.seekTable = new SeekTable();
            this.seekTable.Points = new[]
            {
                new SeekPoint()
                {
                    SampleNumber = 0,
                    StreamOffset = 0,
                    FrameSamples = this.streamInfo.MinBlockSize,
                },
                new SeekPoint()
                {
                    SampleNumber = SeekPoint.Placeholder,
                    StreamOffset = 1000,
                    FrameSamples = this.streamInfo.MinBlockSize,
                }
            };
            
            this.application1 = new Application();
            this.application1.Id = Encoding.ASCII.GetBytes("This");
            this.application1.Data = new byte[] { 0xF0, 0xE1, 0xD2, 0xC3 };

            this.application2 = new Application();
            this.application2.Id = Encoding.ASCII.GetBytes("Here");

            this.vorbisComment = new VorbisComment();
            this.vorbisComment.Vendor = "libFLACnet";
            this.vorbisComment.Comments = new[]
            {
                "ab=cd",
            };

            this.cueSheet = new CueSheet();
            this.cueSheet.MediaCatalogNumber[0] = 'j';
            this.cueSheet.MediaCatalogNumber[1] = 'C';
            this.cueSheet.LeadIn = 2 * 44100;
            this.cueSheet.IsCd = true;
            this.cueSheet.Tracks = new[]
            {
                new Track()
                {
                    Type = 0,
                    Number = 1,
                    ISRC = "ACBDE1234567",
                    PreEmphasis = 1,
                    Indices =
                        new TrackIndex[]
                        {
                            new TrackIndex() { Offset = 0, Number = 0 },
                            new TrackIndex() { Offset = 123 * 588, Number = 1 }
                        },
                },
                new Track()
                {
                    Offset = 1234 * 588,
                    Number = 2,
                    ISRC = "ACBDE7654321",
                    Type = 1,
                    PreEmphasis = 0,
                    Indices = new TrackIndex[]
                    {
                        new TrackIndex { Offset = 0, Number = 1 },
                    }
                },
                new Track()
                {
                    Offset = 12345 * 588,
                    Number = 170,
                }
            };

            this.picture = new Picture();
            this.picture.Type = PictureType.FrontCover;
            this.picture.MimeType = "image/jpeg";
            this.picture.Description = "desc";
            this.picture.Width = 300;
            this.picture.Height = 300;
            this.picture.Depth = 24;
            this.picture.Colors = 0;
            this.picture.Data = Encoding.ASCII.GetBytes("SOMEJPEGDATA");

            this.unknown = new CustomMetadata();
            this.unknown.IsLast = true;
            this.unknown.Type = (MetadataType)126;
            this.unknown.Length = 8;
            this.unknown.Data = new byte[] { 0xFE, 0xDC, 0xBA, 0x98, 0xF0, 0xE1, 0xD2, 0xC3 };
        }
    }
}
